#include "Camera.hpp"

using namespace camera;

Camera::Camera() {
	this->mViewMatrix = glm::mat4(1.0f);
	this->mProjectionMatrix = glm::mat4(1.0f);

	this->mCameraPos = glm::vec3(0.0f, 0.0f, 0.0f);
	this->mCameraFront = glm::vec3(0.0f, -1.0f, -0.1f);
	this->mCameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

}

glm::mat4 Camera::getViewMatrix() {
	return this->mViewMatrix;
}

glm::mat4 Camera::getProjectionMatrix() {
	return this->mProjectionMatrix;
}