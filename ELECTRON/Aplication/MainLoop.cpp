#include <iostream>
#include <string>
#include <thread>
#include "Aplication/MainLoop.h"
#include "Window/Window.h"
#include "Shader/Shader.h"
#include "Camera/Camera.h"
#include "Model/Model.h"
#include "Aplication/relativepath.h"


#include "Engine/Transform/Transform.h"
#include "Gui/Gui.h"



void App::RUN()
{
	Core::Window& window = Core::Window::getInstanse();
	Core::Camera camera(glm::vec3(0.0, 0.0, 3.0));


	Core::Shader shader1 (relpath + "/Electron/Stuff/vs.glsl", relpath + "/Electron/Stuff/f_light.glsl");
	shader1.Bind();
	Transform tran1(shader1);
	Core::Model model1;
	model1.loadModel(relpath + "/Electron/ASSETS/Model/car.fbx");
	
	
	

	//glEnable(GL_CULL_FACE);

	int w, h;
	//window.SetClearColor(glm::vec3(0.5,0.5,0.7));
	while (!glfwWindowShouldClose(window.getGLFWwindow()))
	{
		glfwGetWindowSize(window.getGLFWwindow(),&w,&h);
		window.Update();
		camera.Update();
		tran1.UpdateCam(camera.GetViewMatrix(), camera.GetCameraPos(), camera.GetCameraFront(),w,h);

















		



		shader1.Bind();
		model1.Draw(shader1);






		window.PoolEvents();

	}




}