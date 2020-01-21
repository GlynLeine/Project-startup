#include <iostream>
#include <string>

#include "glm.hpp"

#include "mge/core/rendering/Renderer.hpp"
#include "mge/core/rendering/Mesh.hpp"
#include "mge/core/rendering/Texture.hpp"
#include "mge/core/rendering/Camera.hpp"
#include "mge/core/rendering/Skybox.h"

#include "mge/core/World.hpp"
#include "mge/core/GameObject.hpp"

#include "mge/lights/Light.h"
#include "mge/lights/SpotLight.h"
#include "mge/lights/AreaLight.h"
#include "mge/lights/DirectionalLight.h"

#include "mge/materials/AbstractMaterial.hpp"
#include "mge/materials/ColorMaterial.hpp"
#include "mge/materials/TextureMaterial.hpp"
#include "mge/materials/PBRMaterial.hpp"
#include "mge/materials/BlinnPhongMaterial.hpp"

#include "mge/behaviours/RotatingBehaviour.hpp"
#include "mge/behaviours/KeysBehaviour.hpp"
#include "mge/behaviours/TargetBehaviour.h"
#include "mge/behaviours/OrbitBehaviour.h"
#include "mge/behaviours/AlignBehaviour.hpp"
#include "mge/behaviours/CustomParticle.h"

#include "mge/util/DebugHud.hpp"

#include "mge/config.hpp"
#include "mge/MGEDemo.hpp"

//construct the game class into _window, _renderer and hud (other parts are initialized by build)
MGEDemo::MGEDemo() :AbstractGame(true), _hud(0)
{
}

void MGEDemo::initialize() {
	//setup the core part
	AbstractGame::initialize();

	//setup the custom part so we can display some text
	std::cout << "Initializing HUD" << std::endl;
	_hud = new DebugHud(this);
	std::cout << "HUD initialized." << std::endl << std::endl;
}



//build the game _world
void MGEDemo::_initializeScene()
{
	//MESHES

	//load a bunch of meshes we will be using throughout this demo
	//each mesh only has to be loaded once, but can be used multiple times:
	//F is flat shaded, S is smooth shaded (normals aligned or not), check the models folder!
	Mesh* planeMeshDefault = Mesh::Load(config::MGE_MODEL_PATH + "plane.obj");
	Mesh* cubeMeshF = Mesh::Load(config::MGE_MODEL_PATH + "cube_flat.obj");
	Mesh* sphereMeshS = Mesh::Load(config::MGE_MODEL_PATH + "UVSphereSmooth.obj");
	Mesh* sphereMeshSLP = Mesh::Load(config::MGE_MODEL_PATH + "sphere_smooth.obj");

	//MATERIALS

	//create some materials to display the cube, the plane and the light
	PBRMaterial* copperMaterial = new PBRMaterial("Copper",
		Texture::load(config::MGE_TEXTURE_PATH + "Copper/copper-albedo.png"),
		Texture::load(config::MGE_TEXTURE_PATH + "Copper/copper-normal.png"),
		Texture::load(config::MGE_TEXTURE_PATH + "Copper/copper-metallic.png"),
		Texture::load(config::MGE_TEXTURE_PATH + "Copper/copper-roughness.png"),
		Texture::load(config::MGE_TEXTURE_PATH + "Copper/copper-ao.png"),
		Texture::load(config::MGE_TEXTURE_PATH + "Copper/copper-height.png"));

	PBRMaterial* aluminumMaterial = new PBRMaterial("Aluminum",
		Texture::load(config::MGE_TEXTURE_PATH + "Aluminum/aluminum-albedo.png"),
		Texture::load(config::MGE_TEXTURE_PATH + "Aluminum/aluminum-normal.png"),
		Texture::load(config::MGE_TEXTURE_PATH + "Aluminum/aluminum-metallic.png"),
		Texture::load(config::MGE_TEXTURE_PATH + "Aluminum/aluminum-roughness.png"),
		Texture::load(config::MGE_TEXTURE_PATH + "Aluminum/aluminum-ao.png"),
		Texture::load(config::MGE_TEXTURE_PATH + "Aluminum/aluminum-height.png"));

	PBRMaterial* slateMaterial = new PBRMaterial("Slate",
		Texture::load(config::MGE_TEXTURE_PATH + "Slate/slate-albedo.png"),
		Texture::load(config::MGE_TEXTURE_PATH + "Slate/slate-normal.png"),
		Texture::load(config::MGE_TEXTURE_PATH + "Slate/slate-metallic.png"),
		Texture::load(config::MGE_TEXTURE_PATH + "Slate/slate-roughness.png"),
		Texture::load(config::MGE_TEXTURE_PATH + "Slate/slate-ao.png"),
		Texture::load(config::MGE_TEXTURE_PATH + "Slate/slate-height.png"));

	PBRMaterial* rockMaterial = new PBRMaterial("Rock",
		Texture::load(config::MGE_TEXTURE_PATH + "Rock/rock-albedo.png"),
		Texture::load(config::MGE_TEXTURE_PATH + "Rock/rock-normal.png"),
		Texture::load(config::MGE_TEXTURE_PATH + "Rock/rock-metallic.png"),
		Texture::load(config::MGE_TEXTURE_PATH + "Rock/rock-roughness.png"),
		Texture::load(config::MGE_TEXTURE_PATH + "Rock/rock-ao.png"),
		Texture::load(config::MGE_TEXTURE_PATH + "Rock/rock-height.png"));

	//SCENE SETUP

   //add camera first (it will be updated last)
	Camera* camera = new Camera("camera", glm::vec3(0, 3, 1));
	_world->add(camera);
	_world->setMainCamera(camera);


	GameObject* floor = new GameObject("floor", glm::vec3(0, -10, 0));
	floor->scaleLocal(glm::vec3(10, 10, 10));
	floor->setMesh(planeMeshDefault);
	floor->setMaterial(PBRMaterial::defaultMaterial);
	_world->add(floor);

	GameObject* ceiling = new GameObject("ceiling", glm::vec3(0, 10, 0));
	ceiling->scaleLocal(glm::vec3(10, 10, 10));
	ceiling->rotateLocal(glm::radians(180.f), glm::vec3(1, 0, 0));
	ceiling->setMesh(planeMeshDefault);
	ceiling->setMaterial(PBRMaterial::defaultMaterial);
	_world->add(ceiling);

	GameObject* wall0 = new GameObject("wall0", glm::vec3(0, 0, -10));
	wall0->scaleLocal(glm::vec3(10, 10, 10));
	wall0->rotateLocal(glm::radians(90.f), glm::vec3(1, 0, 0));
	wall0->setMesh(planeMeshDefault);
	wall0->setMaterial(slateMaterial);
	_world->add(wall0);

	GameObject* wall1 = new GameObject("wall1", glm::vec3(0, 0, 10));
	wall1->scaleLocal(glm::vec3(10, 10, 10));
	wall1->rotateLocal(glm::radians(-90.f), glm::vec3(1, 0, 0));
	wall1->rotateLocal(glm::radians(180.f), glm::vec3(0, 1, 0));
	wall1->setMesh(planeMeshDefault);
	wall1->setMaterial(slateMaterial);
	_world->add(wall1);

	GameObject* wall2 = new GameObject("wall2", glm::vec3(10, 0, 0));
	wall2->scaleLocal(glm::vec3(10, 10, 10));
	wall2->rotateLocal(glm::radians(90.f), glm::vec3(0, 0, 1));
	wall2->rotateLocal(glm::radians(-90.f), glm::vec3(0, 1, 0));
	wall2->setMesh(planeMeshDefault);
	wall2->setMaterial(slateMaterial);
	_world->add(wall2);

	GameObject* wall3 = new GameObject("wall3", glm::vec3(-10, 0, 0));
	wall3->scaleLocal(glm::vec3(10, 10, 10));
	wall3->rotateLocal(glm::radians(-90.f), glm::vec3(0, 0, 1));
	wall3->rotateLocal(glm::radians(90.f), glm::vec3(0, 1, 0));
	wall3->setMesh(planeMeshDefault);
	wall3->setMaterial(slateMaterial);
	_world->add(wall3);

	//add a spinning sphere
	GameObject* sphere = new GameObject("sphere", glm::vec3(2.5, 0, 0));
	sphere->scaleLocal(glm::vec3(2.5, 2.5, 2.5));

	sphere->setMesh(sphereMeshS);
	sphere->setMaterial(copperMaterial);
	_world->add(sphere);

	GameObject* sphere0 = new GameObject("sphere0", glm::vec3(7.5, 0, 0));
	sphere0->scaleLocal(glm::vec3(2.5, 2.5, 2.5));
	sphere0->setMesh(sphereMeshS);
	sphere0->setMaterial(aluminumMaterial);
	_world->add(sphere0);

	GameObject* sphere2 = new GameObject("sphere2", glm::vec3(-2.5, 0, 0));
	sphere2->scaleLocal(glm::vec3(2.5, 2.5, 2.5));
	sphere2->setMesh(sphereMeshS);
	sphere2->setMaterial(rockMaterial);
	sphere2->addBehaviour(new RotatingBehaviour(0.1f));
	_world->add(sphere2);

	GameObject* sphere3 = new GameObject("sphere3", glm::vec3(-7.5, 0, 0));
	sphere3->scaleLocal(glm::vec3(2.5, 2.5, 2.5));
	sphere3->setMesh(sphereMeshS);
	sphere3->setMaterial(slateMaterial);
	sphere3->addBehaviour(new RotatingBehaviour(0.1f));
	_world->add(sphere3);


	//add a light. Note that the light does ABSOLUTELY ZIP! NADA ! NOTHING !
	//It's here as a place holder to get you started.
	//Note how the texture material is able to detect the number of lights in the scene
	//even though it doesn't implement any lighting yet!

	GameObject* player = new GameObject("player", glm::vec3(0, 3, 0));
	player->scaleLocal(glm::vec3(0.5, 0.5, 0.5));
	player->setMesh(sphereMeshS);
	player->setMaterial(copperMaterial);
	player->addBehaviour(new KeysBehaviour(10, 10));
	player->addBehaviour(new AlignBehaviour(camera));
	_world->add(player);

	GameObject* core = new GameObject("player core", glm::vec3(0, 3, 0));
	core->addBehaviour(new RotatingBehaviour(3.f));
	_world->add(core);
	core->setParent(player);

	Light* orbitBlock = new AreaLight("orbit block", glm::vec3(0.5, 2.5, 0));
	orbitBlock->rotateLocal(glm::radians(90.f), glm::vec3(1, 0, 0));
	orbitBlock->scaleLocal(glm::vec3(0.1f, 0.1f, 0.1f));

	glm::vec3 colour = glm::vec3(1, 1, 0);

	orbitBlock->SetColour(colour);

	orbitBlock->setMesh(cubeMeshF);
	orbitBlock->setMaterial(new ColorMaterial(colour));
	orbitBlock->SetAttenuation(1);
	orbitBlock->SetIntensity(1);
	orbitBlock->addBehaviour(new RotatingBehaviour(5));
	_world->add(orbitBlock);
	orbitBlock->setParent(core);

	//Light* directionLight = new DirectionalLight("direction light", glm::vec3(0));
	//directionLight->rotateLocal(glm::radians(45.f), glm::vec3(0, 1, 0));
	//directionLight->rotateLocal(glm::radians(-20.f), glm::vec3(1, 0, 0));
	//directionLight->SetIntensity(1.f);
	//directionLight->SetColour(glm::vec3(1, 1, 0.5f));
	//_world->add(directionLight);

	SpotLight* spotLight = new SpotLight("spot light", glm::vec3(0, 5, -9.5f));
	spotLight->scaleLocal(glm::vec3(0.1f, 0.1f, 0.1f));
	spotLight->setMesh(cubeMeshF);
	spotLight->setMaterial(new ColorMaterial(glm::vec3(1, 1, 1)));
	spotLight->rotateLocal(glm::radians(-90.f), glm::vec3(1, 0, 0));
	spotLight->SetAttenuation(50.f);
	spotLight->SetIntensity(2.f);
	spotLight->SetColour(glm::vec3(1, 1, 1));
	spotLight->SetAngle(glm::radians(30.f));
	spotLight->SetFalloffPower(1.f);
	_world->add(spotLight);

	const int colourCount = 5;

	glm::vec4 colours[colourCount];
	ColorMaterial* lightMaterials[colourCount];

	for (int i = 0; i < colourCount; i++)
	{
		float b = (float)(std::rand() % 255) / 255.f;
		float g = glm::max((float)(std::rand() % 255) / 255.f, glm::min(b * 2.f, 1.f));
		glm::vec4 colour = glm::vec4(1, g, b, 0.f);
		colour *= 1.f / glm::max(colour.r, colour.g, colour.b);
		colour.a = 1.f;
		colours[i] = colour;
		lightMaterials[i] = new ColorMaterial(colour);
	}

	int lightCount = _world->getLightCount();
	for (int i = 0; i < (int)config::MAX_LIGHT_COUNT - lightCount + 9839; i++)
	{
		Light* light0 = new AreaLight("point light" + std::to_string(i), glm::vec3((float)(std::rand() % 1800 - 900) / 100.f, (float)(std::rand() % 1800 - 900) / 100.f, (float)(std::rand() % 1800 - 900) / 100.f));
		light0->setLocalScale(glm::vec3(0.05f));
		light0->setMesh(cubeMeshF);
		int colourIndex = std::rand() % colourCount;
		light0->SetColour(colours[colourIndex]);
		light0->setMaterial(lightMaterials[colourIndex]);
		light0->SetAttenuation(6.5);
		light0->SetIntensity(0.5f);

		light0->addBehaviour(new CustomParticle(glm::vec3(-9.8f), glm::vec3(9.8f), 0.5f, glm::vec3((std::rand() % 100) / 100.f, (std::rand() % 100) / 100.f, (std::rand() % 100) / 100.f)));

		_world->add(light0);
	}

	OrbitBehaviour* orbitBehaviour = new OrbitBehaviour(player, 5.f, true);
	camera->addBehaviour(orbitBehaviour);

	TargetBehaviour* targetBehaviour = new TargetBehaviour();
	targetBehaviour->SetTarget(player);
	camera->addBehaviour(targetBehaviour);

	TargetBehaviour* target1Behaviour = new TargetBehaviour();
	target1Behaviour->SetTarget(player);
	sphere->addBehaviour(target1Behaviour);

	std::cout << _world->getLightCount() << " lights registered." << std::endl;
}

void MGEDemo::_render()
{
	AbstractGame::_render();
	_hud->draw();
}

void MGEDemo::_update(float pStep)
{
	AbstractGame::_update(pStep);
	_updateHud(pStep);
}

std::string removeTrail(std::string str)
{
	if (str.find('.') != std::string::npos)
	{
		// Remove trailing zeroes
		str = str.substr(0, str.find_last_of('.') + 3);
	}
	else
		str += ".00";

	return str;
}

void MGEDemo::_updateHud(float pStep) {

	std::string frametime = removeTrail(std::to_string((int)(pStep * 100000) / 100.f));

	std::string cputime = removeTrail(std::to_string((int)(cpuTime * 100000) / 100.f));
	std::string gputime = removeTrail(std::to_string((int)(gpuTime * 100000) / 100.f));

	std::string debugInfo = "";
	debugInfo += std::string("FPS:") + std::to_string((int)_fps) + std::string("\nFrame time: ") + frametime + std::string("ms");
	if (config::VSYNC_ENABLED)
		debugInfo += std::string("\nV-Sync enabled");
	else
		debugInfo += std::string("\nV-Sync disabled");

	sf::Vector2u windowSize = getWindow()->getSize();
	debugInfo += std::string("\nresolution: ") + std::to_string(windowSize.x) + std::string("x") + std::to_string(windowSize.y);

	debugInfo += std::string("\n\nBatch count: ") + std::to_string(_world->GetBatchCount());
	debugInfo += std::string("\nObject count: ") + std::to_string(_world->GetObjectCount());
	debugInfo += std::string("\nState changes: ") + std::to_string(Renderer::stateChanges);
	debugInfo += std::string("\nDraw calls: ") + std::to_string(Renderer::stateChanges);
	debugInfo += std::string("\nObjects rendered: ") + std::to_string(Renderer::objectsRendered);

	debugInfo += std::string("\n\nCpu time: ") + cputime + std::string("ms");
	debugInfo += std::string(" Gpu time: ") + gputime + std::string("ms");

	debugInfo += std::string("\n\n\n") + contextInfo;


	_hud->setDebugInfo(debugInfo);
	_hud->appendFrameTime(pStep);
}

MGEDemo::~MGEDemo()
{
	//dtor
}
