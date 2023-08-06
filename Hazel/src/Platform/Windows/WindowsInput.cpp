#include "hzpch.h"
#include "WindowsInput.h"
#include "Hazel/Application.h"

#include <GLFW/glfw3.h>


namespace Hazel {

	Input* Input::s_Instance = new WindowsInput();

	bool Hazel::WindowsInput::IsKeyPressedImp(int keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::IsMouseButtonPressedImp(int button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> WindowsInput::GetMousePositionImp()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);
		return { (float)xPos, (float)yPos };
	}

	float WindowsInput::GetMouseXImp()
	{
		auto [x, y] = GetMousePositionImp();
		return x;
	}

	float WindowsInput::GetMouseYImp()
	{
		auto [x, y] = GetMousePositionImp();
		return y;
	}
}
