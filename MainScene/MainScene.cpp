#include "MainScene.hpp"

using namespace scene;

MainScene::MainScene() : COrthoCam() {
	this->intialize();
}

void MainScene::run() {
	
	constexpr std::chrono::nanoseconds time_step(16ms);
	using clock = std::chrono::high_resolution_clock;
	auto curr_time = clock::now();
	auto prev_time = curr_time;
	std::chrono::nanoseconds curr_ns(0);

	Particle CParticle = Particle();
	//InputManager::getInstance()->askUserVelocity(CParticle.getVelocity());
	CParticle.setVelocity(Vector(1.0f/100.0f, 0.0f, 0.0f));
	CParticle.setAcceleration(Vector(1.0f/-30.0f, 0.0f, 0.0f));

	while (!glfwWindowShouldClose(this->pWindow)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		curr_time = clock::now();
		auto durr = std::chrono::duration_cast<std::chrono::nanoseconds>(curr_time - prev_time);
		prev_time = curr_time;
		curr_ns += durr;
		if (curr_ns >= time_step) {
			auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(curr_ns);
			//std::cout << "MS: " << (float)ms.count() << "\n";
			curr_ns -= curr_ns;
			//std::cout << "P6 Update" << std::endl;
			CParticle.Update((float)ms.count() / 1000);
		}

		//std::cout << "Normal Update" << std::endl;
		this->update();
		this->vecModels[0]->getTransform()->setAtt(TransformAtt::TRANSLATE, CParticle.getPosition()->getCoordinates());
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
	pSphere->getTransform()->setAtt(TransformAtt::TRANSLATE, glm::vec3(0.0f, 0.0f, 0.0f));
	this->vecModels.push_back(pSphere);
	
}

void MainScene::update() {
	this->vecModels[0]->getTransform()->calculateTransformMatrix();

}

void MainScene::render() {
	
	this->vecModels[0]->draw("Sphere");
	this->COrthoCam.draw("Sphere");

}
