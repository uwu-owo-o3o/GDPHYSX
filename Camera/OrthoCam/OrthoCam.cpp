#include "OrthoCam.hpp"

using namespace camera;

OrthoCam::OrthoCam() : Camera() {
	this->fLeft = -2.0f;
	this->fRight = 2.0f;
	this->fBottom = -2.0f;
	this->fTop = 2.0f;
	this->fNear = -1.0f;
	this->fFar = 1.0f;
}

void OrthoCam::draw(std::string strKey) {
	this->mViewMatrix = glm::lookAt(this->mCameraPos, this->mCameraPos + this->mCameraFront, this->mCameraUp);
	this->mProjectionMatrix = glm::ortho(0.0f, SCREEN_WIDTH, 0.0f, SCREEN_HEIGHT, -450.0f, 350.0f);
	//glOrtho(0.0f, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, 0.0f, 1.0f);
	//glm::ortho(this->fLeft, this->fRight, this->fBottom, this->fTop, this->fNear, this->fFar);
	auto modelShader = ShaderManager::getInstance()->getShader(strKey);

	unsigned int projectionLoc = glGetUniformLocation(*modelShader, "projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(this->mProjectionMatrix));

	unsigned int viewLoc = glGetUniformLocation(*modelShader, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(this->mViewMatrix));

}