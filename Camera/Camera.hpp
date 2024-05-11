#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace camera {
	class Camera {
		protected:
			glm::mat4 mViewMatrix;
			glm::mat4 mProjectionMatrix;

			glm::vec3 mCameraPos;
			glm::vec3 mCameraUp;
			glm::vec3 mCameraFront;

		public:
			Camera();
		public:
			glm::mat4 getViewMatrix();
			glm::mat4 getProjectionMatrix();
		
	};
}