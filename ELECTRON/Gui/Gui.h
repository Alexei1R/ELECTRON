#include <iostream>
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include "Window/Window.h"

namespace Gui
{



	class MyGui
	{
	private:
		GLFWwindow* m_window = nullptr;
		//Gui::MyGui::ImGuiIO& io = ImGui::GetIO();// (void)io;
	public:
		MyGui(GLFWwindow* window);
		void NewFrame();
		void Setup();
		void Render();


	};
	


}



