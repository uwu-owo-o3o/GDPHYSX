#pragma once

#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>

#include "iostream"

namespace shader {
	class ShaderManager {
		private:
			std::unordered_map<std::string, GLuint*> mapShaders;
			
		private:
			ShaderManager();
			~ShaderManager();

		public:
			void loadShader(std::string key, std::string path, unsigned int shader_type);
			void registerShaders();

		private:
			static ShaderManager* P_SHARED_INSTANCE;
			ShaderManager& operator = (const ShaderManager&);
		public:
			static ShaderManager* getInstance();
			GLuint* getShader(std::string strKey);

	};
}