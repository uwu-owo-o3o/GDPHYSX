#include "RenderParticle.hpp"

using namespace component;

RenderParticle::RenderParticle(Particle* pParticle, Model3D* pModel3D, Vector Color) {
	this->pReferenceParticle = pParticle;
	this->pReferenceModel = pModel3D;
	this->CColor = Color;
}

void RenderParticle::Draw() {
	if (!this->pReferenceParticle->checkIfDestroyed()) {
		this->pReferenceModel->getTransform()->setAtt(TransformAtt::TRANSLATE, this->pReferenceParticle->getPosition()->getCoordinates());
		this->pReferenceModel->draw("Sphere");
	}
}