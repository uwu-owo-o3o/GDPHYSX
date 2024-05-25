#include "InputManager.hpp"

using namespace input;

InputManager::InputManager() {

}

InputManager::~InputManager() {
  
}

void InputManager::askUserVelocity(Vector* pVector) {
    float x;
    float y;
    float z;

    std::cout << "Velocity: " << std::endl;
    std::cout << "X: ";
    std::cin >> x;
    std::cout << std::endl;


    std::cout << "Y: ";
    std::cin >> y;
    std::cout << std::endl;


    std::cout << "Z: ";
    std::cin >> z;
    std::cout << std::endl;

    pVector->setCoordinates(glm::vec3(x, y, z));
    
}

InputManager* InputManager::P_SHARED_INSTANCE = NULL;

InputManager* InputManager::getInstance() {
    if (P_SHARED_INSTANCE == NULL) {
        P_SHARED_INSTANCE = new InputManager();
    }
    return P_SHARED_INSTANCE;
}

