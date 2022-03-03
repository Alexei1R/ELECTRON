#pragma once
#include <string>
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"


namespace Core
{
	
	

	class Window final
	{
	public:

		std::string name;
		int m_width;
		int m_height;

		
		GLFWwindow* window = nullptr;
	public:
		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;

	private:
		Window(const std::string& name, int width, int height);
	private:
		~Window();
	public:
		static Window& getInstanse() { static Window instanse("Window", 1280, 720); return instanse; }

		void SetClearColor(glm::vec3 color);
		void Update();
		void PoolEvents();
		void WaitEvents();
	public:
		void init(const std::string& name, int width, int height);
		__forceinline GLFWwindow* getGLFWwindow() const { return window; }
		
	private:
		static void window_size_callback(GLFWwindow* window, int width, int height);
	};


}