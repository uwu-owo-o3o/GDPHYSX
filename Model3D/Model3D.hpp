#pragma once

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include "ObjData/ObjData.hpp"

#include <glm/gtc/type_ptr.hpp>

#include "../Transform/Transform.hpp"
#include "../Shaders/ShaderManager/ShaderManager.hpp"
namespace model {
	using namespace data;
	using namespace transform;
	using namespace shader;
	class Model3D {
		private:
			ObjData CObjData;
			Transform CTransform;

		private:
			GLuint VAO;
			GLuint VBO;
			
		public:
			Model3D(std::string strPath);
			~Model3D();

		private:
			void initializeBuffers();
			void initalizeTransform();
		public:
			void draw(std::string strKey);
		public:
			Transform* getTransform();
	};
}