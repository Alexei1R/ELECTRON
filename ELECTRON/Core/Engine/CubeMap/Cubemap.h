#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../../Model/Model.h"
#include "../../Shader/Shader.h"
#include <string>




namespace Core
{


    //float skyboxVertices[] = {
    //    // positions          
    //    -100.0f,  100.0f, -100.0f,
    //    -100.0f, -100.0f, -100.0f,
    //     100.0f, -100.0f, -100.0f,
    //     100.0f, -100.0f, -100.0f,
    //     100.0f,  100.0f, -100.0f,
    //    -100.0f,  100.0f, -100.0f,
    //
    //    -100.0f, -100.0f,  100.0f,
    //    -100.0f, -100.0f, -100.0f,
    //    -100.0f,  100.0f, -100.0f,
    //    -100.0f,  100.0f, -100.0f,
    //    -100.0f,  100.0f,  100.0f,
    //    -100.0f, -100.0f,  100.0f,
    //
    //     100.0f, -100.0f, -100.0f,
    //     100.0f, -100.0f,  100.0f,
    //     100.0f,  100.0f,  100.0f,
    //     100.0f,  100.0f,  100.0f,
    //     100.0f,  100.0f, -100.0f,
    //     100.0f, -100.0f, -100.0f,
    //
    //    -100.0f, -100.0f,  100.0f,
    //    -100.0f,  100.0f,  100.0f,
    //     100.0f,  100.0f,  100.0f,
    //     100.0f,  100.0f,  100.0f,
    //     100.0f, -100.0f,  100.0f,
    //    -100.0f, -100.0f,  100.0f,
    //
    //    -100.0f,  100.0f, -100.0f,
    //     100.0f,  100.0f, -100.0f,
    //     100.0f,  100.0f,  100.0f,
    //     100.0f,  100.0f,  100.0f,
    //    -100.0f,  100.0f,  100.0f,
    //    -100.0f,  100.0f, -100.0f,
    //
    //    -100.0f, -100.0f, -100.0f,
    //    -100.0f, -100.0f,  100.0f,
    //     100.0f, -100.0f, -100.0f,
    //     100.0f, -100.0f, -100.0f,
    //    -100.0f, -100.0f,  100.0f,
    //     100.0f, -100.0f,  100.0f
    //};
    float skyboxVertices[] = {
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
     0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
    };
    GLuint loadCubemap(std::vector<std::string> faces)
    {
        GLuint textureID;
        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

        int width, height, nrChannels;
        for (unsigned int i = 0; i < faces.size(); i++)
        {
            unsigned char* data = stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
            if (data)
            {
                glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
                    0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data
                );
                stbi_image_free(data);
            }
            else
            {
                std::cout << "Cubemap texture failed to load at path: " << faces[i] << std::endl;
                stbi_image_free(data);
            }
        }
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

        return textureID;
    }




	class SkyBox
	{
    private:
        std::string m_path;
        unsigned int skyboxVAO, skyboxVBO;
        std::vector<std::string> faces =
        {
                (m_path + "right.jpg"),
                (m_path + "left.jpg"),
                (m_path + "top.jpg"),
                (m_path + "bottom.jpg"),
                (m_path + "front.jpg"),
                (m_path + "back.jpg")
        };

        unsigned int cubemapTexture = loadCubemap(faces);


	public:
		SkyBox(std::string path)
			:m_path(path)
		{
            
            glGenVertexArrays(1, &skyboxVAO);
            glGenBuffers(1, &skyboxVBO);
            glBindVertexArray(skyboxVAO);
            glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
		}


        void SendUniformTexture(Core::Shader& skyboxShader)
        {
            skyboxShader.Bind();
            skyboxShader.SetUniform1i("skybox", 0);
        };


		void Draw(Core::Shader& skyboxShader)
		{
            glDepthFunc(GL_LEQUAL);  // change depth function so depth test passes when values are equal to depth buffer's content
            skyboxShader.Bind();
            // skybox cube
            glBindVertexArray(skyboxVAO);
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
            glDrawArrays(GL_TRIANGLES, 0, 36);
            glBindVertexArray(0);
            glDepthFunc(GL_LESS); // set depth function back to default


		};




	};

};