#include <Systems/Movement2System.h>
#include <Components/Input.h>
void Args::Movement2System::Init()
{
	BindForUpdate(std::bind(&Movement2System::Update, this, std::placeholders::_1));
	GetGlobalComponent <Args::Input>()->BindAxis("RotateX",std::bind(&Movement2System::Rotate,this,std::placeholders::_1,std::placeholders::_2));
	GetGlobalComponent<Args::Input>()->BindAxis("MoveY", std::bind(&Movement2System::Move,this,std::placeholders::_1,std::placeholders::_2));
}

void Args::Movement2System::Start()
{
}


void Args::Movement2System::Update(float deltaTime)
{
	Movement2Component* movement;
	Transform* transform;
	GetComponents(&movement, &transform);
	transform->Move(movement->CurrentVel*deltaTime);
	transform->SetForward(Args::rotate(transform->GetForward(), movement->angle * deltaTime, Args::up));
	transform->SetRotation((Args::Matrix3)Args::inverse(Args::lookAtLH(Args::zero, transform->GetForward(), Args::up)));
}

void Args::Movement2System::Move(int controllerID, float dir)
{
	for (auto entity : GetEntityList())
	{
		Movement2Component* movement = GetComponent<Movement2Component>(entity);
		Transform* transform = GetComponent<Transform>(entity);
		Args::Vector3 fwd = transform->GetForward();
		fwd.y = 0;
		movement->CurrentVel = Args::normalize(fwd) * -dir;
	}
}

void Args::Movement2System::Rotate(int controlllerID,float angleStep)
{
	for (auto entity : GetEntityList())
	{
		Movement2Component* movement = GetComponent<Movement2Component>(entity);
		Transform* transform = GetComponent<Transform>(entity);

		movement->angle = -angleStep * movement->RotateSpeed;
	}
}

void Args::Movement2System::Print(float deltaTime)
{
}
