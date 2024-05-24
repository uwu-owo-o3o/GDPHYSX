#pragma once

#include "../Vector.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace component {
	class Particle {
		private:
			float mass;
			Vector CPosition;
			Vector CVelocity;
			Vector CAcceleration;
		public:
			Particle();
		public:
			void UpdatePosition(float time);
			void Update(float time);
		public:
			Vector getPosition();
			void setPosition(Vector CVector);
			Vector getVelocity();
			void setVelocity(Vector CVector);
			Vector getAcceleration();
			void setAcceleration(Vector CVector);
	};
}