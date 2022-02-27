#include <iostream>
#include "window.h"
#include "Event/keyboard.h"
#include "Event/mouse.h"
#include <sstream>




Core::Window::Window(const std::string& name, int width, int height)
{
	init(name, width, height);
}

void Core::Window::init(const std::string& name, int width, int height)
{


	this->name = name;
	this->width = width;
	this->height = height;

	// check glfw init

	if (!glfwInit())
	{
		std::cout << "glfw don't init";
	}
	window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);

	// check window init
	if (!window)
	{
		std::cout << "window don't init";
	}

	glfwMakeContextCurrent(window);

	
	if (glewInit() != GLEW_OK)
		std::cout << "GLEW failed..." << std::endl;

	glfwSetWindowUserPointer(window, this);
	glfwSetCursorPosCallback(window, Mouse::cursorPosCallback);
	glfwSetScrollCallback(window, Mouse::mouseWheelCallback);
	glfwSetMouseButtonCallback(window, Mouse::mouseButtonCallback);
	glfwSetKeyCallback(window, Keyboard::keyCallback);
	glfwSetWindowSizeCallback(window, window_size_callback);



	glClearColor(0.1, 0.1, 0.1, 1.0);
	glEnable(GL_DEPTH_TEST);
}

void Core::Window::window_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void Core::Window::SetClearColor(glm::vec3 color)
{
	glClearColor(color.x, color.y, color.z, 1.0);
}


void Core::Window::Update()
{

	//if (Keyboard::key(GLFW_KEY_ESCAPE)) { glfwSetWindowShouldClose(window, GLFW_TRUE); }
	if (Keyboard::key(GLFW_KEY_F1)) { glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); }
	if (Keyboard::key(GLFW_KEY_F2)) { glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL); }


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}
void Core::Window::PoolEvents()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void Core::Window::WaitEvents()
{
	glfwSwapBuffers(window);
	glfwWaitEvents();
}





Core::Window::~Window()
{
	glfwWindowShouldClose(window);
}

