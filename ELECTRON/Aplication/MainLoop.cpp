#include <iostream>
#include <string>
#include "Aplication/MainLoop.h"
#include "Window/Window.h"
#include "Shader/Shader.h"
#include "Camera/Camera.h"
#include "Model/Model.h"
#include "Aplication/relativepath.h"


#include "Engine/Transform/Transform.h"



void App::RUN()
{
	Core::Window& window = Core::Window::getInstanse();
	
	Core::Shader shader (relpath + "/Electron/Stuff/vs.glsl", relpath + "/Electron/Stuff/fs.glsl");
	shader.Bind();
	Core::Model model (relpath + "/Electron/ASSETS/Model/torus3.fbx");
	
	Core::Camera camera(glm::vec3(0.0, 0.0, 3.0));


	Transform tran(shader);































	

	


	int w, h;
	
	while (!glfwWindowShouldClose(window.getGLFWwindow()))
	{
		glfwGetWindowSize(window.getGLFWwindow(),&w,&h);
		window.Update();
		camera.Update();
		tran.UpdateCam(camera.GetViewMatrix(), camera.GetCameraPos(), camera.GetCameraFront(),w,h);






		
		model.Draw(shader);






		window.PoolEvents();

	}



}