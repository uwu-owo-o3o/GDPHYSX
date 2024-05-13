#include "Vector.hpp"

using namespace component;

Vector::Vector(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->calculateMagnitude();
}

void Vector::calculateMagnitude() {
	this->fMagnitude = sqrt(pow(this->x, 2) + pow(y, 2) + pow(z, 2));
}

glm::vec3 Vector::add(Vector CVector) {
	float fX = this->x + CVector.x;
	float fY = this->y + CVector.y;
	float fZ = this->z + CVector.z;
	return glm::vec3(fX, fY, fZ);
}

glm::vec3 Vector::subtract(Vector CVector) {
	float fX = this->x - CVector.x;
	float fY = this->y - CVector.y;
	float fZ = this->z - CVector.z;
	return glm::vec3(fX, fY, fZ);
}

glm::vec3 Vector::scalarMultiply(float fScalar) {
	float fX = this->x * fScalar;
	float fY = this->y * fScalar;
	float fZ = this->z * fScalar;
	return glm::vec3(fX, fY, fZ);
}

glm::vec3 Vector::componentMultiply(Vector CVector) {
	float fX = this->x * CVector.x;
	float fY = this->y * CVector.y;
	float fZ = this->z * CVector.z;
	return glm::vec3(fX, fY, fZ);
}

float Vector::calculateScalarProduct(Vector CVector) {
	return (this->x * CVector.x) + (this->y * CVector.y) + (this->z * CVector.z);
}

glm::vec3 Vector::calculateVectorProduct(Vector CVector) {
	float fX = (this->y * CVector.z) - (this->z * CVector.y);
	float fY = (this->z * CVector.x) - (this->x * CVector.z);
	float fZ = (this->x * CVector.y) - (this->y * CVector.x);
	return glm::vec3(fX, fY, fZ);
}

void Vector::calculateDirection() {
	float fNormal = 1 / this->fMagnitude;
	float fNormalX = fNormal * this->x;
	float fNormalY = fNormal * this->y;
	float fNormalZ = fNormal * this->z;
	this->mDirection = glm::vec3(fNormalX, fNormalY, fNormalZ);
}

float Vector::getX() {
	return this->x;
}

void Vector::setX(float x) {
	this->x = x;
}

float Vector::getY() {
	return this->y;
}

void Vector::setY(float y) {
	this->y = y;
}

float Vector::getZ() {
	return this->z;
}

void Vector::setZ(float z) {
	this->z = z;
}

glm::vec3 Vector::getVector() {
	return glm::vec3(this->x, this->y, this->z);
}