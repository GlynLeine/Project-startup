#include <Systems\Movement2System.h>
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


}

void Args::Movement2System::Move(int controllerID, float dir)
{
	Movement2Component* moveComp;
	Transform* transform;
	GetComponents(&moveComp, &transform);

	Args::Vector3 fwd = transform->GetForward();
	fwd.y = 0;

	transform->Move(Args::normalize(fwd) * dir * -moveComp->MoveSpeed);
}

void Args::Movement2System::Rotate(int controlllerID,float angleStep)
{
	Movement2Component* moveComp;
	Transform* transform;
	GetComponents(&moveComp, &transform);

	Args::Vector3 fwd = transform->GetForward();
	fwd = Args::rotate(fwd, -angleStep * moveComp->RotateSpeed, Args::up);

	transform->SetRotation((Args::Matrix3)Args::inverse(Args::lookAtLH(Args::zero, fwd, Args::up)));
}

void Args::Movement2System::Print(float deltaTime)
{
}
