#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "iostream"

#include "../Model3D/Model3D.hpp"
#include "../Physics/Component/Vector.hpp"
#include "../Camera/OrthoCam/OrthoCam.hpp"

#include "chrono"
#include "../Physics/Component/Particle/Particle.hpp"
#include "../InputManager/InputManager.hpp"
#include "../Config/Settings.hpp"
#include "../../Controller/SimController/SimController.hpp"

namespace scene {
	using namespace model;
	using namespace camera;
	using namespace component;
	using namespace input;
	using namespace controller;
	using namespace std::chrono_literals;
	class MainScene {
		private:
			GLFWwindow* pWindow;
			std::vector<Model3D*> vecModels;
			OrthoCam COrthoCam;
			Particle CParticle;
			SimController CSimController;
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

