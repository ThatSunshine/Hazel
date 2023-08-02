#include <Hazel.h>


class Example : public Hazel::Layer
{
public:
	Example()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		HZ_INFO("ExampleLayer: Update");
	}

	void OnEvent(Hazel::Event& event) override
	{
		HZ_TRACE("{0}", event);
	}
};


class Sandbox : public Hazel::Application
{
public:
	Sandbox() 
	{
		PushLayer(new Example());
		PushOverlay(new Hazel::ImGuiLayer());
	}
	~Sandbox() {}
};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}
