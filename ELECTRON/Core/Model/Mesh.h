#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>
#include <string>
#include <sstream>
#include "Shader/Shader.h"


struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

struct  Texture
{
    unsigned int id;
    std::string type;
    std::string path;
};




namespace Core
{


    class Mesh
    {
    private:
        unsigned int VAO, VBO, EBO;
    public:
        std::vector<Vertex> vertices;
        std::vector<unsigned int > indices;
        std::vector<Texture> textures;
    public:
        Mesh(std::vector<Vertex>vertices, std::vector<unsigned int>indices, std::vector<Texture>textures);
        void Draw(Core::Shader& shader);
    private:
        void setupMesh();


    };

}














