#include "Skybox.h"
#include "Mesh.hpp"
#include "Texture.hpp"
#include "mge/core/World.hpp"
#include "Camera.hpp"
#include "mge/materials/TextureMaterial.hpp"
#include "mge/config.hpp"


Skybox::Skybox(Texture* hdri) : GameObject("Skybox")
{
	texture = hdri;
}

Skybox::~Skybox()
{
}

void Skybox::init()
{
	setMaterial(new TextureMaterial(texture));
	setMesh(Mesh::Load(config::MGE_MODEL_PATH + "skybox.obj"));
	setWorldScale(glm::vec3(100, 100, 100));
}

void Skybox::update(float pStep)
{
	setWorldPosition(_world->getMainCamera()->getWorldPosition());
}

void Skybox::SetTexture(Texture * hdri)
{
	dynamic_cast<TextureMaterial*>(_material)->setDiffuseTexture(hdri);
}

//void Skybox::SetTexture(Texture * forward, Texture * right, Texture * back, Texture * left, Texture * up, Texture * down)
//{
//}
