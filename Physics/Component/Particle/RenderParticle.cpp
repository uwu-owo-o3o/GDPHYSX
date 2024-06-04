#include "RenderParticle.hpp"

using namespace component;

RenderParticle::RenderParticle(Particle* pParticle, Model3D* pModel3D, Vector Color) {
	this->pReferenceParticle = pParticle;
	this->pReferenceModel = pModel3D;
	this->CColor = Color;
}

void RenderParticle::Draw() {
	if (!this->pReferenceParticle->checkIfDestroyed()) {
		auto modelShader = ShaderManager::getInstance()->getShader("Sphere");
		unsigned int colorLoc = glGetUniformLocation(*modelShader, "ParticleColor");
		//std::cout << "Color x: " << this->CColor.getX() << std::endl;
		glm::vec4 color = glm::vec4(this->CColor.getX(), this->CColor.getY(), this->CColor.getZ(), 1.0f);
		glUniform4fv(colorLoc, 1, glm::value_ptr(color));

		this->pReferenceModel->getTransform()->setAtt(TransformAtt::TRANSLATE, this->pReferenceParticle->getPosition()->getCoordinates());
		this->pReferenceModel->draw("Sphere");
	}
}