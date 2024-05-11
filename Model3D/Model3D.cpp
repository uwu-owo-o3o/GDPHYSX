#include "Model3D.hpp"

using namespace model;

Model3D::Model3D(std::string strPath) : CObjData(strPath), CTransform() {
	this->initializeBuffers();
	this->initalizeTransform();
}

Model3D::~Model3D() {
	glDeleteVertexArrays(1, &this->VAO);
	glDeleteBuffers(1, &this->VBO);
}

void Model3D::initializeBuffers() {
	glGenVertexArrays(1, &this->VAO);
	glGenBuffers(1, &this->VBO);
}

void Model3D::initalizeTransform() {
	//this->CTransform.calculateTransformMatrix();
}

void Model3D::draw(std::string strKey) {

	auto modelShader = ShaderManager::getInstance()->getShader(strKey);

	glBindVertexArray(this->VAO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

	glBufferData(GL_ARRAY_BUFFER, 
		         sizeof(GLfloat) * this->CObjData.getFullVertexData().size(),
				 this->CObjData.getFullVertexData().data(),
		         GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	unsigned int transformLoc = glGetUniformLocation(*modelShader, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(*this->CTransform.getTransformMatrix()));

	glUseProgram(*modelShader);
	glBindVertexArray(this->VAO);
	glDrawArrays(GL_TRIANGLES, 0, this->CObjData.getFullVertexData().size() / 3);

	glBindVertexArray(0);
}

Transform* Model3D::getTransform() {
	return &this->CTransform;
}