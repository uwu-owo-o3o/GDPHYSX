#pragma once

#include "../Vector.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "iostream"

namespace component {
	class Particle {
		private:
			float damping;
			Vector CPosition;
			Vector CVelocity;
			Vector CAcceleration;
			Vector CAccumulatedForce;
			bool isDestroyed;

		public:
			std::string name;
			float time;
			float magnitudeVelocity;
			float mass;
			float radius = 50.0f;
			float restitution = 1.0f;
		public:
			Particle();
		public:
			void UpdatePosition(float time);
			void UpdateVelocity(float time);
			void Update(float time);
			void Destroy();
			bool checkIfDestroyed();
			void AddForce(Vector force);
			void ResetForce();
		public:
			Vector* getPosition();
			void setPosition(Vector CVector);
			Vector* getVelocity();
			void setVelocity(Vector CVector);
			Vector* getAcceleration();
			void setAcceleration(Vector CVector);
	};
}