#include "hzpch.h"
#include "Application.h"
#include "Hazel/Log.h"
#include "Hazel/Events/ApplicationEvent.h"


namespace Hazel {

    Application::Application()
    {
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			HZ_INFO(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			HZ_INFO(e);
		}
		while (true);
	}
}