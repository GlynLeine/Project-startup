#pragma once
//#include <Args-Core.h>
#include <string>
#include <functional>
#include <list>
namespace Args
{
	using ControllerID = int32_t;
	delegate void KeyActionDelegate(bool a_pressed, ControllerID a_controllerID = -1);
	public delegate void KeyAxisDelegate(float a_value, std::list<ControllerID> a_controllerID);
	public delegate void KeyButtonDelegate(Key a_key, bool a_pressed, ControllerID a_controllerID = -1);
	
	//JSONLoader jsonLoader;
	class InputSystem //: Args::GlobalSystem<InputSystem>
	{
	public:
		InputSystem(); //: Args::GlobalSystem<InputSystem>() {}
		virtual void Init(); //override;
		void Start();
		void Update(float deltaTime);
	};


	class InputEvent abstract
	{
	public:
		//Delegate m_delegate = NULL;
	};

	class InputButton : InputEvent
	{

	};
}