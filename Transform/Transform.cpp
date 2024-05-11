#include "Transform.hpp"

using namespace transform;

Transform::Transform() {
	this->mTranslation = glm::vec3(0.0f, 0.0f, 0.0f);
	this->mScale = glm::vec3(0.15f, 0.15f, 0.15f);
	this->mRotation = glm::vec3(0.0f, 1.0f, 0.0f);
	this->fRotationTheta = 90.0f;
	this->mTransformMatrix = glm::mat4(1.0f);

}

void Transform::calculateTransformMatrix() {
	glm::mat4 mIdentity = glm::mat4(1.0f);
	this->mTransformMatrix = glm::translate(mIdentity, this->mTranslation);
	this->mTransformMatrix = glm::scale(this->mTransformMatrix, this->mScale);
	this->mTransformMatrix = glm::rotate(this->mTransformMatrix, glm::radians(this->fRotationTheta), glm::normalize(this->mRotation));

}

void Transform::setAtt(TransformAtt EAttribute, glm::vec3 mMatrix) {
	switch (EAttribute) {
		case TransformAtt::TRANSLATE:
			this->mTranslation = mMatrix;
			break;
		case TransformAtt::SCALE:
			this->mScale = mMatrix;
			break;
		case TransformAtt::ROTATION:
			this->mRotation = mMatrix;
			break;
	}
}

glm::vec3 Transform::getAtt(TransformAtt EAttribute) {
	glm::vec3 mMatrix = glm::vec3(0.0f, 0.0f, 0.0f);
	switch (EAttribute) {
		case TransformAtt::TRANSLATE:
			mMatrix = this->mTranslation;
			break;
		case TransformAtt::SCALE:
			mMatrix = this->mScale;
			break;
		case TransformAtt::ROTATION:
			mMatrix = this->mRotation;
			break;
	}

	return mMatrix;
}

glm::mat4* Transform::getTransformMatrix() {
	return &this->mTransformMatrix;
}