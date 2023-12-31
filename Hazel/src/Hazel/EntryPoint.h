#pragma once

#include "Core.h"


#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argav)
{
	Hazel::Log::Init();
	HZ_CORE_CRITICAL("Initiallized  Core Log!");
	HZ_INFO("Hello Client Log!");

	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}

#endif