#pragma once

#include "../Physics/Component/Vector.hpp"
#include "iostream"

namespace input {
	using namespace component;
	class InputManager {
		private:
			InputManager();
			~InputManager();
		public:
			void askUserVelocity(Vector* pVector);
		private:
			static InputManager* P_SHARED_INSTANCE;
			InputManager& operator = (const InputManager&);
		public:
			static InputManager* getInstance();
			
	};
}