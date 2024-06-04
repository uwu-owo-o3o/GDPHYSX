#include "InputManager.hpp"

using namespace input;

InputManager::InputManager() {

}

InputManager::~InputManager() {
  
}

void InputManager::askUserVelocity(Particle* pParticle) {
    float x;
    float y;
    float z;

    std::cout << "Velocity: " << std::endl;
    std::cout << "X: ";
    std::cin >> x;

    std::cout << "Y: ";
    std::cin >> y;

    std::cout << "Z: ";
    std::cin >> z;

    pParticle->setVelocity(Vector(x, y, z));
    
}

InputManager* InputManager::P_SHARED_INSTANCE = NULL;

InputManager* InputManager::getInstance() {
    if (P_SHARED_INSTANCE == NULL) {
        P_SHARED_INSTANCE = new InputManager();
    }
    return P_SHARED_INSTANCE;
}

