#pragma once

#include <GL/glew.h>
#include "glm.hpp"
#include <unordered_map>
#include <vector>

class World;
class GameObject;
class Mesh;
class Camera;
class AbstractMaterial;

/**
* Renderer implements a default single pass forward renderer.
*/
class Renderer
{
public:
	Renderer();
	virtual ~Renderer();

	bool debug;

	/**
	 * Utility call
	 */
	void setClearColor(float pR, float pG, float pB);

	/**
	 * Convenience method to render whole world, visits each gameobject in the world recursively,
	 * using each gameobject's mesh & material, and the world's main camera.
	 */
	void render(World* pWorld);

	/**
	 * Renders a specific GameObject in the world using a specific camera.
	 * Convenience method for calling render (world, gameobject, material, modelmatrix, viewmatrix, projectionmatrix, recursive)
	 *
	 * @param pWorld the world the mesh is a part of, can be used to retrieve lighting information
	 * @param pGameObject the gameobject to render, will use the this gameobject's world transform for the model matrix
	 * @param pMaterial the material to use, is passed on to render (world, gameobject, material, modelmatrix, viewmatrix, projectionmatrix, recursive)
	 * @param pCamera used for the view and perspective matrix
     * @param pRecursive render everything recursively
	 */
	void render(World* pWorld, GameObject* pGameObject, AbstractMaterial* pMaterial, Camera* pCamera, bool pRecursive);

	/**
	 * Renders a specific game object in the world by calling:
	 *  renderSelf
	 *  renderChildren
	 *
	 * @param pWorld the world the gameobject is a part of, can be used to retrieve lighting information
	 * @param pGameObject the gameobject to render
	 * @param pMaterial the material to use, if NULL, the pGameObject->getMaterial() will be used, if NOT null it overrides the material for each and every gameobject
	 * @param pModelMatrix the world transform of the model
	 * @param pViewMatrix the view matrix of the camera
	 * @param pProjectionMatrix the projectionmatrix of the camera
	 * @param pRecursive render everything recursively
	 */
	void render(World* pWorld, GameObject* pGameObject, AbstractMaterial* pMaterial, const glm::mat4& pModelMatrix, const glm::mat4& pViewMatrix, const glm::mat4& pProjectionMatrix, bool pRecursive);

	/**
	* Renders a specific mesh in the world.
	*
	* @param pWorld the world the mesh is a part of, can be used to retrieve lighting information
	* @param pMesh the mesh to render
	* @param pMaterial the material to use, CANNOT be NULL !!
	* @param pModelMatrix the world transform of the model
	* @param pViewMatrix the view matrix of the camera
	* @param pProjectionMatrix the projectionmatrix of the camera
	*/
	void render(World* pWorld, Mesh* pMesh, AbstractMaterial* pMaterial, const glm::mat4& pModelMatrix, const glm::mat4& pViewMatrix, const glm::mat4& pProjectionMatrix);

	/**
	 * Helper method to render debug info for a mesh
	 */
	void renderMeshDebugInfo(Mesh* pMesh, const glm::mat4& pModelMatrix, const glm::mat4& pViewMatrix, const glm::mat4& pProjectionMatrix);

	void render(World* pWorld, Camera* pCamera, std::unordered_map<Mesh*, std::unordered_map<AbstractMaterial*, std::vector<GameObject*>>> batches);

	void init();
	void resetMaterials();
	void reportMaterial(AbstractMaterial* material);

	static void CheckErrors(const char* function = "unknown", int line = 0);

	static AbstractMaterial* defaultMaterial;
	static int stateChanges;
	static int objectsRendered;

protected:
	std::unordered_map<unsigned, AbstractMaterial*> materials;
	/**
	* Renders a specific game object in the world.
	*
	* @param pWorld the world the gameobject is a part of, can be used to retrieve lighting information
	* @param pGameObject the gameobject to render
	* @param pMaterial the material to use, CANNOT BE NULL
	* @param pModelMatrix the world transform of the model
	* @param pViewMatrix the view matrix of the camera
	* @param pProjectionMatrix the projectionmatrix of the camera
	*/
	void renderSelf(World* pWorld, GameObject* pGameObject, AbstractMaterial* pMaterial, const glm::mat4& pModelMatrix, const glm::mat4& pViewMatrix, const glm::mat4& pProjectionMatrix);

	//calls render on each and every child gameobject, material cannot be null!
	void renderChildren(World* pWorld, GameObject* pGameObject, AbstractMaterial* pMaterial, const glm::mat4& pModelMatrix, const glm::mat4& pViewMatrix, const glm::mat4& pProjectionMatrix, bool pRecursive);
};

