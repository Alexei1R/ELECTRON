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

#include "Model/stb_image.h"
#include "Engine/CubeMap/Cubemap.h"




void App::RUN()
{
	Core::Window& window = Core::Window::getInstanse();
	Core::Camera camera(glm::vec3(0.0, 0.0, 3.0));


	Core::Shader shader1 (relpath + "/Electron/Stuff/vs.glsl", relpath + "/Electron/Stuff/f_light.glsl");
	shader1.Bind();
	shader1.SetUniform1i("skybox", 0);
	Transform tran1(shader1);
	Core::Model model1;
	model1.loadModel(relpath + "/Electron/ASSETS/Model/mercedes.fbx");
    tran1.rotateRadians(-90, glm::vec3(1.0, 0.0, 0.0));
    tran1.scale(glm::vec3(0.01, 0.01, 0.01));
	
	//cubemap test
	//===========================================
    Core::Shader skyboxShader(relpath + "/Electron/Stuff/v_sky.glsl", relpath + "/Electron/Stuff/f_sky.glsl");
    Transform tran_sky(skyboxShader);
	tran_sky.scale(glm::vec3(100.0, 100.0, 100.0));
    std::string path_tex = relpath + "/Electron/ASSETS/skybox/";
    Core::SkyBox sky(path_tex);
    sky.SendUniformTexture(skyboxShader);

	

	//glEnable(GL_CULL_FACE);

	int w, h;
	//window.SetClearColor(glm::vec3(0.5,0.5,0.7));
	while (!glfwWindowShouldClose(window.getGLFWwindow()))
	{
		glfwGetWindowSize(window.getGLFWwindow(),&w,&h);
		window.Update();
		camera.Update();
		tran1.UpdateCam(camera.GetViewMatrix(), camera.GetCameraPos(), camera.GetCameraFront(),w,h);
        tran_sky.UpdateCam(camera.GetViewMatrix(), camera.GetCameraPos(), camera.GetCameraFront(),w,h);



		sky.Draw(skyboxShader);









        


		



		shader1.Bind();
		model1.Draw(shader1);






		window.PoolEvents();

	}


}



