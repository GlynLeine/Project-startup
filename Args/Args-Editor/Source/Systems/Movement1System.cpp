#include <Systems/Movement1System.h>
#include <Args-Input.h>

void Args::Movement1System::Init()
{
	BindForUpdate(std::bind(&Movement1System::Update, this, std::placeholders::_1));
	Debug::Success(DebugInfo, "Initialised TestSystem");
	GetGlobalComponent<Args::Input>()->BindAxis("MoveX", std::bind(&Movement1System::DirectionX, this, std::placeholders::_1, std::placeholders::_2));
	GetGlobalComponent<Args::Input>()->BindAxis("MoveY", std::bind(&Movement1System::DirectionY, this, std::placeholders::_1, std::placeholders::_2));
	GetGlobalComponent<Args::Input>()->BindAxis("Exit", std::bind(&Movement1System::Jump, this, std::placeholders::_1, std::placeholders::_2));
}

void Args::Movement1System::DirectionX(Args::ControllerID controller, Args::AxisValue value)
{
	Movement1Component* movement;
	Transform* transform;
	PickupComponent* pickup;
	Rigidbody* rigidbody;
	GetComponents(&movement, &transform, &pickup, &rigidbody);
	movement->Direction.x = value;
}

void Args::Movement1System::DirectionY(Args::ControllerID controller, Args::AxisValue value)
{
	Movement1Component* movement;
	Transform* transform;
	PickupComponent* pickup;
	Rigidbody* rigidbody;
	GetComponents(&movement, &transform, &pickup, &rigidbody);
	movement->Direction.z = value;
}

void Args::Movement1System::Jump(Args::ControllerID controller, Args::AxisValue value)
{
	Movement1Component* movement;
	Transform* transform;
	PickupComponent* pickup;
	Rigidbody* rigidbody;
	GetComponents(&movement, &transform, &pickup, &rigidbody);
	rigidbody->forces.push_back(Vector3(0, 1, 0) * movement->JumpSpeed);
}


void Args::Movement1System::Update(float deltaTime)
{
	Movement1Component* movement;
	Transform* transform;
	PickupComponent* pickup;
	Rigidbody* rigidbody;
	GetComponents(&movement, &transform, &pickup, &rigidbody);
	movement->DeltaTurn = normalize(transform->GetForward() + movement->Direction * movement->RotateSpeed * deltaTime);
	transform->SetForward(movement->DeltaTurn);
	/*if(!pickup->PickingUp)
	{*/
		transform->position += transform->GetForward() * deltaTime * movement->MoveSpeed;
	//}
}


