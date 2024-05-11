#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace transform {

	enum class TransformAtt : int {
		NONE = 0,
		TRANSLATE,
		SCALE,
		ROTATION
	};

	class Transform {
		private:
			glm::vec3 mTranslation;
			glm::vec3 mScale;
			glm::vec3 mRotation;

			float fRotationTheta;
		
		private:
			glm::mat4 mTransformMatrix;

		public:
			Transform();
		public:
			void calculateTransformMatrix();

		public:
			void setAtt(TransformAtt EAttribute, glm::vec3 mMatrix);
			glm::vec3 getAtt(TransformAtt EAttribute);
			glm::mat4* getTransformMatrix();
			
	};
}