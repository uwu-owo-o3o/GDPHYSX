#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "iostream"

#include "../Model3D/Model3D.hpp"

namespace scene {
	using namespace model;
	class MainScene {
		private:
			GLFWwindow* pWindow;
			std::vector<Model3D*> vecModels;
		public:
			MainScene();
		public:
			void run();
		private:
			void intialize();
			void createSphere();
			void update();
			void render();
			
	};
}

