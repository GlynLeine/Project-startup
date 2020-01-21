#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#define NOMINMAX
#include <windows.h>

#include <iostream>
#include "Renderer.hpp"
#include "mge/core/GameObject.hpp"
#include "Camera.hpp"
#include "Mesh.hpp"
#include "mge/core/World.hpp"
#include "mge/materials/AbstractMaterial.hpp"
#include "mge/core/rendering/ShaderProgram.hpp"
#include "mge/materials/PBRMaterial.hpp"

#ifndef MGE_HIGH_PERF
#define MGE_HIGH_PERF
__declspec(dllexport) DWORD NvOptimusEnablement = 0x0000001;
__declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
#endif

AbstractMaterial* Renderer::defaultMaterial = PBRMaterial::defaultMaterial;
int Renderer::stateChanges = 0;
int Renderer::objectsRendered = 0;

Renderer::Renderer() : debug(false)
{
	SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);
}

Renderer::~Renderer()
{
}

void Renderer::setClearColor(float pR, float pG, float pB) {
	glClearColor(pR, pG, pB, 1.0f);
}

void Renderer::render(World* pWorld)
{
	stateChanges = 0;
	objectsRendered = 0;

	//render(pWorld, pWorld, nullptr, pWorld->getMainCamera(), true);
	render(pWorld, pWorld->getMainCamera(), pWorld->getRenderBatches());

	CheckErrors();
}

void Renderer::render(World* pWorld, GameObject* pGameObject, AbstractMaterial* pMaterial, Camera* pCamera, bool pRecursive)
{
	render(pWorld, pGameObject, pMaterial, pGameObject->getWorldTransform(), glm::inverse(pCamera->getWorldTransform()), pCamera->getProjection(), pRecursive);
}

void Renderer::render(World* pWorld, GameObject* pGameObject, AbstractMaterial* pMaterial, const glm::mat4& pModelMatrix, const glm::mat4& pViewMatrix, const glm::mat4& pProjectionMatrix, bool pRecursive) {
	renderSelf(pWorld, pGameObject, pMaterial == nullptr ? pGameObject->getMaterial() : pMaterial, pModelMatrix, pViewMatrix, pProjectionMatrix);
	if (pRecursive) renderChildren(pWorld, pGameObject, pMaterial, pModelMatrix, pViewMatrix, pProjectionMatrix, pRecursive);
}

void Renderer::renderSelf(World* pWorld, GameObject* pGameObject, AbstractMaterial* pMaterial, const glm::mat4& pModelMatrix, const glm::mat4& pViewMatrix, const glm::mat4& pProjectionMatrix) {
	render(pWorld, pGameObject->getMesh(), pMaterial, pModelMatrix, pViewMatrix, pProjectionMatrix);
	if (debug) renderMeshDebugInfo(pGameObject->getMesh(), pModelMatrix, pViewMatrix, pProjectionMatrix);
}

void Renderer::renderChildren(World* pWorld, GameObject* pGameObject, AbstractMaterial* pMaterial, const glm::mat4& pModelMatrix, const glm::mat4& pViewMatrix, const glm::mat4& pProjectionMatrix, bool pRecursive) {
	int childCount = pGameObject->getChildCount();
	if (childCount < 1) return;

	//note that with a loop like this, deleting children during rendering is not a good idea :)
	GameObject* child = 0;
	for (int i = 0; i < childCount; i++) {
		child = pGameObject->getChildAt(i);
		render(pWorld, child, pMaterial, pModelMatrix * child->getTransform(), pViewMatrix, pProjectionMatrix, pRecursive);
	}
}

void Renderer::render(World* pWorld, Mesh* pMesh, AbstractMaterial* pMaterial, const glm::mat4& pModelMatrix, const glm::mat4& pViewMatrix, const glm::mat4& pProjectionMatrix) {
	if (pMesh != nullptr && pMaterial != nullptr)
	{
		if (materials[pMaterial->id] == nullptr)
			reportMaterial(pMaterial);

		stateChanges++;
		objectsRendered++;

		pMaterial->render(pWorld, pMesh, pModelMatrix, pViewMatrix, pProjectionMatrix);
	}
}

void Renderer::renderMeshDebugInfo(Mesh* pMesh, const glm::mat4& pModelMatrix, const glm::mat4& pViewMatrix, const glm::mat4& pProjectionMatrix) {
	if (pMesh != nullptr) pMesh->DrawDebugInfo(pModelMatrix, pViewMatrix, pProjectionMatrix);
}

void Renderer::render(World* pWorld, Camera* pCamera, std::unordered_map<Mesh*, std::unordered_map<AbstractMaterial*, std::vector<GameObject*>>> batches)
{
	for (auto& batch : batches)
	{
		if (!batch.first)
			continue;

		Mesh* mesh = batch.first;
		for (auto& materialGroup : batch.second)
		{
			AbstractMaterial* material;

			if (!materialGroup.first)
				material = defaultMaterial;
			else
				material = materialGroup.first;

			if (materials[material->id] == nullptr)
				reportMaterial(material);

			material->Bind(pWorld, glm::inverse(pCamera->getWorldTransform()), pCamera->getProjection(), mesh);

			stateChanges++;

			std::vector<glm::mat4> modelMatrices = std::vector<glm::mat4>();
			for (GameObject* instance : materialGroup.second)
			{
				modelMatrices.push_back(instance->getWorldTransform());
			}

			objectsRendered += modelMatrices.size();

			material->Draw(modelMatrices, mesh);

			material->Release(mesh);
		}
	}
}

void Renderer::init()
{
	//make sure we test the depthbuffer
	glEnable(GL_DEPTH_TEST);

	//tell opengl which vertex winding is considered to be front facing
	glFrontFace(GL_CCW);

	//tell opengl to enable face culling for the back faces
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void Renderer::resetMaterials()
{
	for (auto& material : materials)
	{
		if (!material.second->valid())
			continue;

		material.second->devalidate();
	}

	for (auto& material : materials)
	{
		if (material.second->valid())
			continue;
		material.second->LazyInitializeShader();
		std::cout << "Re-initialised material \"" << material.second->name.substr(0, material.second->name.find_last_of(' ')) << "\"." << std::endl << std::endl;
	}
}

void Renderer::reportMaterial(AbstractMaterial * material)
{
	materials[material->id] = material;
	if (!material->valid())
	{
		material->LazyInitializeShader();
		std::cout << "Initialised material \"" << material->name.substr(0, material->name.find_last_of(' ')) << "\"." << std::endl << std::endl;
	}

	std::cout << "Registered material \"" << material->name << "\" to renderer." << std::endl;
}

void Renderer::CheckErrors(const char* function, int line)
{
	GLenum error;
	while ((error = glGetError()) != GL_NO_ERROR)
	{
		std::string errorString = "";
		switch (error) {
		case GL_INVALID_OPERATION:				errorString = "INVALID_OPERATION";				break;
		case GL_INVALID_ENUM:					errorString = "INVALID_ENUM";					break;
		case GL_INVALID_VALUE:					errorString = "INVALID_VALUE";					break;
		case GL_OUT_OF_MEMORY:					errorString = "OUT_OF_MEMORY";					break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:  errorString = "INVALID_FRAMEBUFFER_OPERATION";  break;
		}

		std::cout << "OpenGL error: " << errorString << std::endl;
		std::cout << "	function:	" << function << "\n	line:	" << line << std::endl;
	}
}

