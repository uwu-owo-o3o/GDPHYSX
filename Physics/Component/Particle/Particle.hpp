#pragma once

#include "../Vector.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "iostream"

namespace component {
	class Particle {
		private:
			float mass;
			Vector CPosition;
			Vector CVelocity;
			Vector CAcceleration;
			bool isDestroyed;
		public:
			std::string name;
			float time;
			float magnitudeVelocity;
		public:
			Particle();
		public:
			void UpdatePosition(float time);
			void UpdateVelocity(float time);
			void Update(float time);
			void Destroy();
			bool checkIfDestroyed();
		public:
			Vector* getPosition();
			void setPosition(Vector CVector);
			Vector* getVelocity();
			void setVelocity(Vector CVector);
			Vector* getAcceleration();
			void setAcceleration(Vector CVector);
	};
}