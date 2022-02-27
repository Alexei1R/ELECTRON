#include "MainLoop.h"
#include "Window/Window.h"
#include "Shader/Shader.h"
#include "Camera/Camera.h"

void App::RUN()
{

	Core::Window& window = Core::Window::getInstanse();
	





	
	while (!glfwWindowShouldClose(window.getGLFWwindow()))
	{
		window.Update();










		window.PoolEvents();

	}



}