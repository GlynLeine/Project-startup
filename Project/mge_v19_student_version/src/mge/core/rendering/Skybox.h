#include "mge/core/GameObject.hpp"

class Texture;
class TextureMaterial;

class Skybox : public GameObject
{
public:
	Skybox(Texture * hdri);
	~Skybox();

	virtual void init() override;
	virtual void update(float pStep) override;
	void SetTexture(Texture* hdri);
	//void SetTexture(Texture* forward, Texture* right, Texture* back, Texture* left, Texture* up, Texture* down);
private:
	Texture* texture;
};