#include "ShaderManager.hpp"

using namespace shader;

ShaderManager::ShaderManager() {
    this->mapShaders["Sphere"] = NULL;
}

ShaderManager::~ShaderManager() {
    for (auto i : this->mapShaders) {
        if (i.second)
            delete i.second;
    }
}

void ShaderManager::loadShader(std::string key, std::string path, unsigned int shader_type) {

    std::fstream shaderSrc(path);
    
    std::stringstream shaderBuff;
    shaderBuff << shaderSrc.rdbuf();

    std::string shaderS = shaderBuff.str();
    const char* s = shaderS.c_str();

    //Initializing Shaders
    GLuint shader = glCreateShader(shader_type);
    glShaderSource(shader, 1, &s, NULL);
    glCompileShader(shader);

    if (this->mapShaders[key] == NULL) {
        this->mapShaders[key] = new GLuint(glCreateProgram());
    }

    glAttachShader(*this->mapShaders[key], shader);
}

void ShaderManager::registerShaders() {
    auto pCopy = this->getInstance();
    pCopy->loadShader("Sphere", "Shaders/unlit.vert", GL_VERTEX_SHADER);
    pCopy->loadShader("Sphere", "Shaders/unlit.frag", GL_FRAGMENT_SHADER);

    glLinkProgram(*this->mapShaders["Sphere"]);
}

ShaderManager* ShaderManager::P_SHARED_INSTANCE = NULL;

ShaderManager* ShaderManager::getInstance() {
    if (P_SHARED_INSTANCE == NULL) {
        P_SHARED_INSTANCE = new ShaderManager();
    }
    return P_SHARED_INSTANCE;
}

GLuint* ShaderManager::getShader(std::string strKey) {
    return this->mapShaders[strKey];
}