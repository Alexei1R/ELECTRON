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
	Core::Camera camera(glm::vec3(0.0, 0.0, 3.0));


	Core::Shader shader1 (relpath + "/Electron/Stuff/vs.glsl", relpath + "/Electron/Stuff/f_light.glsl");
	shader1.Bind();
	Transform tran1(shader1);
	Core::Model model1(relpath + "/Electron/ASSETS/Model/car.fbx");
	
	//tran1.scale(glm::vec3(0.01, 0.01, 0.01));
	//tran1.rotateRadians(90.0f,glm::vec3(1.0,0.0,0.0));
	//tran1.rotateRadians(180.0f,glm::vec3(0.0,1.0,0.0));


	Core::Shader shader2(relpath + "/Electron/Stuff/vs.glsl", relpath + "/Electron/Stuff/f_light.glsl");
	shader2.Bind();
	Transform tran2(shader2);
	Core::Model model2(relpath + "/Electron/ASSETS/Model/car.fbx");

	//tran2.transform(glm::vec3(0.0, -2.0, 0.0));





	tran2.transform(glm::vec3(0.0, 0.0, 2.0));




	int w, h;
	//window.SetClearColor(glm::vec3(0.5,0.5,0.7));
	while (!glfwWindowShouldClose(window.getGLFWwindow()))
	{
		glfwGetWindowSize(window.getGLFWwindow(),&w,&h);
		window.Update();
		camera.Update();
		tran1.UpdateCam(camera.GetViewMatrix(), camera.GetCameraPos(), camera.GetCameraFront(),w,h);
		tran2.UpdateCam(camera.GetViewMatrix(), camera.GetCameraPos(), camera.GetCameraFront(),w,h);








		shader1.Bind();
		model1.Draw(shader1);


		shader2.Bind();
		model2.Draw(shader2);


		window.PoolEvents();

	}




}