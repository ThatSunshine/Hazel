#include <Hazel.h>

#include "imgui/imgui.h"

class Example : public Hazel::Layer
{
public:
	Example()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Hazel::Input::IsKeyPressed(HZ_KEY_TAB))
			HZ_TRACE("tab key is pressed (poll)");
	}

	virtual void OnImGuiRender() override
	{
	}

	void OnEvent(Hazel::Event& event) override
	{
		if (event.GetEventType() == Hazel::EventType::KeyPressed)
		{
			Hazel::KeyPressedEvent& e = (Hazel::KeyPressedEvent&)event;
			if (e.GetKeyCode() == HZ_KEY_TAB)
				HZ_TRACE("tab key is pressed (evnet)");
			HZ_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};


class Sandbox : public Hazel::Application
{
public:
	Sandbox() 
	{
		PushLayer(new Example());
	}
	~Sandbox() {}
};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}
