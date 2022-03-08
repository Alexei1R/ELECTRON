#pragma once
#include <iostream>
#include "Model/Mesh.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "Model/stb_image.h"


namespace Core
{

	class Model
	{
	public:
		int count = 0;
		std::vector<Core::Mesh> meshes;
		std::string directory;
		std::vector<Texture> textures_loaded;
		
	public:
		
		Model(std::string path);
		void Draw(Core::Shader& shader);

	private:
		void loadModel(std::string path);
		void processNode(aiNode* node, const aiScene* scene);
		Core::Mesh processMesh(aiMesh* mesh, const aiScene* scene);
		std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
		unsigned int TextureFromFile(const char* path, const std::string& directory);//, bool gamma);

	};

}