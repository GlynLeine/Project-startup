#include <iostream>
#include "GameObject.hpp"
#include "mge/behaviours/AbstractBehaviour.hpp"

GameObject::GameObject(const std::string& pName, const glm::vec3& pPosition)
	: _name(pName), _transform(glm::translate(pPosition)), _parent(nullptr), _children(),
	_mesh(nullptr), _behaviours(std::unordered_map<std::type_index, AbstractBehaviour*>()), _material(nullptr), _world(nullptr)

{
}

GameObject::~GameObject()
{
	while (_children.size() > 0) {
		GameObject* child = _children[0];
		remove(child);
		delete child;
	}

	//do not forget to delete behaviour, material, mesh, collider manually if required!
}

void GameObject::setName(const std::string& pName)
{
	_name = pName;
}

std::string GameObject::getName() const
{
	return _name;
}

void GameObject::setTransform(const glm::mat4& pTransform)
{
	_transform = pTransform;
}

const glm::mat4& GameObject::getTransform() const
{
	return _transform;
}

void GameObject::setLocalPosition(glm::vec3 pPosition)
{
	_transform[3] = glm::vec4(pPosition, 1);
}

void GameObject::setLocalScale(glm::vec3 pScale)
{
	_transform[0] = glm::normalize(_transform[0]) * pScale.x;
	_transform[1] = glm::normalize(_transform[1]) * pScale.y;
	_transform[2] = glm::normalize(_transform[2]) * pScale.z;
}

void GameObject::setLocalRotation(glm::mat3 pRotation)
{
	glm::vec3 scale = getLocalScale();
	_transform[0] = glm::vec4(glm::normalize(pRotation[0]) * scale.x, _transform[0].w);
	_transform[1] = glm::vec4(glm::normalize(pRotation[1]) * scale.y, _transform[1].w);
	_transform[2] = glm::vec4(glm::normalize(pRotation[2]) * scale.z, _transform[2].w);
}

glm::vec3 GameObject::getLocalPosition() const
{
	return glm::vec3(_transform[3]);
}

glm::vec3 GameObject::getLocalScale() const
{
	return glm::vec3(glm::length(_transform[0]), glm::length(_transform[1]), glm::length(_transform[2]));
}

glm::mat3 GameObject::getLocalRotation() const
{
	return glm::mat3(glm::normalize(_transform[0]), glm::normalize(_transform[1]), glm::normalize(_transform[2]));
}

void GameObject::setWorldPosition(glm::vec3 pPosition)
{
	glm::mat4 transform = getWorldTransform();
	setLocalPosition(glm::inverse(transform) * glm::vec4(pPosition, 1));
}

void GameObject::setWorldScale(glm::vec3 pScale)
{
	glm::vec3 worldScale = getWorldScale();
	setLocalScale(glm::vec3(1.f / worldScale.x, 1.f / worldScale.y, 1.f / worldScale.z) * pScale);
}

void GameObject::setWorldRotation(glm::mat3 pRotation)
{
	glm::mat3 worldRotation = getWorldRotation();
	setLocalRotation(glm::inverse(worldRotation) * pRotation);
}

void GameObject::setMaterial(AbstractMaterial* pMaterial)
{
	_material = pMaterial;
}

AbstractMaterial * GameObject::getMaterial() const
{
	return _material;
}

void GameObject::setMesh(Mesh* pMesh)
{
	_mesh = pMesh;
}

Mesh * GameObject::getMesh() const
{
	return _mesh;
}


//void GameObject::addBehaviour(AbstractBehaviour* pBehaviour)
//{
//	_behaviour = pBehaviour;
//	_behaviour->setOwner(this);
//}
//
//AbstractBehaviour* GameObject::getBehaviour() const
//{
//    return _behaviour;
//}

void GameObject::setParent(GameObject* pParent) {
	//remove from previous parent
	if (_parent != nullptr) {
		_parent->_innerRemove(this);
	}

	//set new parent
	if (pParent != nullptr) {
		setTransform(glm::inverse(pParent->getWorldTransform()) * getWorldTransform());
		pParent->_innerAdd(this);
	}

	//if we have been detached from our parent, make sure
	//the world reference for us and all our children is set to null
	//if we have been attached to a parent, make sure
	//the world reference for us and all our children is set to our parent world reference
	//(this could still be null if the parent or parent's parent is not attached to the world)
	if (_parent == nullptr) {
		_setWorldRecursively(nullptr);
	}
	else {
		//might still not be available if our parent is not part of the world
		_setWorldRecursively(_parent->_world);
	}
}

void GameObject::_innerRemove(GameObject* pChild) {
	for (auto i = _children.begin(); i != _children.end(); ++i) {
		if (*i == pChild) {
			_children.erase(i);
			pChild->_parent = nullptr;
			return;
		}
	}
}

void GameObject::_innerAdd(GameObject* pChild)
{
	_children.push_back(pChild);
	pChild->_parent = this;
}

void GameObject::add(GameObject* pChild) {
	pChild->setParent(this);
}

void GameObject::remove(GameObject* pChild) {
	pChild->setParent(nullptr);
}

GameObject* GameObject::getParent() const {
	return _parent;
}

////////////

//costly operation, use with care
glm::vec3 GameObject::getWorldPosition() const
{
	return glm::vec3(getWorldTransform()[3]);
}

glm::vec3 GameObject::getWorldScale() const
{
	glm::mat4 transform = getWorldTransform();
	return glm::vec3(glm::length(transform[0]), glm::length(transform[1]), glm::length(transform[2]));
}

glm::mat3 GameObject::getWorldRotation() const
{
	glm::mat4 transform = getWorldTransform();
	return glm::mat3(glm::normalize(transform[0]), glm::normalize(transform[1]), glm::normalize(transform[2]));
}

//costly operation, use with care
glm::mat4 GameObject::getWorldTransform() const
{
	if (_parent == nullptr) return _transform;
	else return _parent->getWorldTransform() * _transform;
}

////////////

void GameObject::translateLocal(glm::vec3 pTranslation)
{
	setTransform(glm::translate(_transform, pTranslation));
}

void GameObject::scaleLocal(glm::vec3 pScale)
{
	setTransform(glm::scale(_transform, pScale));
}

void GameObject::rotateLocal(float pAngle, glm::vec3 pAxis)
{
	setTransform(glm::rotate(_transform, pAngle, pAxis));
}

void GameObject::init()
{
	//make sure behaviour is updated after worldtransform is set
	if (_behaviours.size() > 0)
	{
		for (auto iterator = _behaviours.begin(); iterator != _behaviours.end(); iterator++)
		{
			iterator->second->init();
		}
	}

	for (int i = _children.size() - 1; i >= 0; --i) {
		_children[i]->init();
	}
}

void GameObject::update(float pStep)
{
	//make sure behaviour is updated after worldtransform is set
	if (_behaviours.size() > 0)
	{
		for (auto iterator = _behaviours.begin(); iterator != _behaviours.end(); iterator++)
		{
			iterator->second->update(pStep);
		}
	}

	for (int i = _children.size() - 1; i >= 0; --i) {
		_children[i]->update(pStep);
	}
}

void GameObject::_setWorldRecursively(World* pWorld) {
	_world = pWorld;

	for (int i = _children.size() - 1; i >= 0; --i) {
		_children[i]->_setWorldRecursively(pWorld);
	}
}

int GameObject::getChildCount() const {
	return _children.size();
}

GameObject* GameObject::getChildAt(int pIndex) const {
	return _children[pIndex];
}

