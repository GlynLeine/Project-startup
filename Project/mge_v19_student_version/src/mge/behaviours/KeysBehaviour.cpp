#include "mge/behaviours/KeysBehaviour.hpp"
#include "mge/core/GameObject.hpp"
#include <SFML/Window/Keyboard.hpp>

KeysBehaviour::KeysBehaviour(float pMoveSpeed, float pStriveSpeed) : AbstractBehaviour(), _moveSpeed(pMoveSpeed), _riseSpeed(pMoveSpeed), _striveSpeed(pStriveSpeed)
{
}

KeysBehaviour::~KeysBehaviour()
{
}

void KeysBehaviour::update(float pStep)
{
	float moveSpeed = 0.0f; //default if no keys
	float riseSpeed = 0.0f;
	float striveSpeed = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		moveSpeed = -_moveSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		moveSpeed = _moveSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		striveSpeed = _striveSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		striveSpeed = -_striveSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		riseSpeed = _riseSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		riseSpeed = -_riseSpeed;
	}

	//translate the object in its own local space
	_owner->translateLocal(glm::vec3(striveSpeed*pStep, riseSpeed*pStep, moveSpeed*pStep));

	//we can also translate directly, basically we take the z axis from the matrix
	//which is normalized and multiply it by moveSpeed*step, then we add it to the
	//translation component
	//glm::mat4 transform = _owner->getTransform();
	//transform[3] += transform[2] * moveSpeed*pStep;
	//_owner->setTransform(transform);

	//rotate the object in its own local space
	//_owner->rotateLocal(glm::radians(striveSpeed*pStep), glm::vec3(0.0f, 1.0f, 0.0f));

	//NOTE:
	//The reason the above happens in the local space of the object and not in the world space
	//is that we use the _owner->translate / rotate shortcuts which in turn call glm::rotate / glm::translate
	//The methods multiply the current transform with the translation/rotation matrix from left to right
	//meaning everything happens in local space.
}
