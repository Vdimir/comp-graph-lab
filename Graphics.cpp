//
// Created by deffe on 15.03.16.
//

#include "Graphics.h"


Graphics::Graphics() {
    glfwInit();
    glfwOpenWindow(800, 600, 8, 8, 8, 0, 0, 0, GLFW_WINDOW);
}

Graphics::~Graphics() {
    glfwTerminate();
}

bool Graphics::isWindowOpened() const {
    return glfwGetWindowParam(GLFW_OPENED) == GL_TRUE;
}

int Graphics::update(Canvas &canvas) const {
    if(isWindowOpened()) {
        canvas.draw();
        return 1;
    }
    return 0;
}

const Graphics& Graphics::getInstance() {
    static Graphics _instance;
    return _instance;
}


