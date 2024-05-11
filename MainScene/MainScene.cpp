#include "MainScene.hpp"

using namespace scene;

MainScene::MainScene() : COrthoCam() {
	this->intialize();
}

void MainScene::run() {
	while (!glfwWindowShouldClose(this->pWindow)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		this->update();
		this->render();

		glfwSwapBuffers(this->pWindow);
		glfwPollEvents();
	}

	glfwTerminate();
}

void MainScene::intialize() {
	if (!glfwInit()) {
		std::cout << "glfwInit has encountered an error!" << std::endl;
	}
	this->pWindow = glfwCreateWindow(600, 600, "Ong, Lance", NULL, NULL);
	glfwMakeContextCurrent(this->pWindow);
	gladLoadGL();

	ShaderManager::getInstance()->registerShaders();
	this->createSphere();
}

void MainScene::createSphere() {
	Model3D* pSphere = new Model3D("3D/sphere.obj");
	this->vecModels.push_back(pSphere);
}

void MainScene::update() {
	this->vecModels[0]->getTransform()->calculateTransformMatrix();
}

void MainScene::render() {
	
	this->vecModels[0]->draw("Sphere");
	this->COrthoCam.draw("Sphere");

}
