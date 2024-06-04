#pragma once

#include "../Physics/Component/Particle/Particle.hpp"
#include "iostream"

namespace input {
	using namespace component;
	class InputManager {
		private:
			float sample;
		private:
			InputManager();
			~InputManager();
		public:
			void askUserVelocity(Particle* pParticle);
		private:
			static InputManager* P_SHARED_INSTANCE;
			InputManager& operator = (const InputManager&);
		public:
			static InputManager* getInstance();
			
	};
}