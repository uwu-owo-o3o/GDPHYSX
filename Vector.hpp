#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace component {
	class Vector {
		private:
			float x, y, z;
			float fMagnitude;
			glm::vec3 mDirection;

		public:
			Vector(float x, float y, float z);
		public:
			void calculateMagnitude();
			void calculateDirection();

		public:
			glm::vec3 add(Vector CVector);
			glm::vec3 subtract(Vector CVector);
			glm::vec3 scalarMultiply(float fScalar);
			glm::vec3 componentMultiply(Vector CVector);
			float calculateScalarProduct(Vector CVector);
			glm::vec3 calculateVectorProduct(Vector CVector);

		public:
			float getX();
			float getY();
			float getZ();
			void setX(float x);
			void setY(float y);
			void setZ(float z);
			glm::vec3 getVector();
			

	};
}