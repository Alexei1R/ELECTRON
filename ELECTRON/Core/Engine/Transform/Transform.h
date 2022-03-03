#pragma once 
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader/Shader.h"




class Transform
{
private:
	Core::Shader shader;

	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 proj = glm::mat4(1.0f);
	glm::mat4 model = glm::mat4(1.0f);
	glm::vec3 camPos = glm::vec3(0.0f,0.0f,0.0f);
	glm::vec3 camFront = glm::vec3(0.0f, 0.0f, 0.0f);


public:
	Transform(Core::Shader& shader);



private:





public:
	void SendUniform();

	void UpdateCam(glm::mat4 viewmat, glm::vec3 camPos, glm::vec3 camFront, float w_height, float w_width);
	void rotate(float angle, glm::vec3 vector);
	void transform(glm::vec3 vector);
	void scale(glm::vec3 vector);
	




};