#ifndef WORLD_HPP
#define WORLD_HPP

#include "mge/core/GameObject.hpp"

class Camera;
class Light;

class World : public GameObject
{
	public:
        World();

		void setMainCamera (Camera* pCamera);
		Camera* getMainCamera();

        //only used internally, do not use from outside
        void registerLight (Light* pLight);
        void unregisterLight (Light* pLight);

        Light* getLightAt (int pIndex);
        int getLightCount();

		virtual void add(GameObject* obj) override;
		virtual void remove(GameObject* obj) override;

		std::unordered_map<Mesh*, std::unordered_map<AbstractMaterial*, std::vector<GameObject*>>> getRenderBatches();
		unsigned GetBatchCount();
		unsigned GetObjectCount();

	private:
		std::unordered_map<Mesh*, std::unordered_map<AbstractMaterial*, std::vector<GameObject*>>> batches;
		unsigned batchCount;
		unsigned objectCount;

	    Camera* _mainCamera;
	    std::vector<Light*> _lights;

        World(const World&);
        World& operator=(const World&);
};


#endif // WORLD_HPP
