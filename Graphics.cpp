//
// Created by deffe on 15.03.16.
//

#include "Graphics.h"

Graphics::Graphics() {
    glfwInit();
    this->window = glfwCreateWindow(800, 600, "My Title",NULL, NULL);
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GL_TRUE);
    });

    glClearColor(1, 1, 1, 1);
    glColor3f(0, 0, 0);

    glClear(GL_COLOR_BUFFER_BIT);
}

Graphics::~Graphics() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

int Graphics::update() const {

    if(glfwWindowShouldClose(window)) {
        return 0;
    }
    glfwSwapBuffers(this->window);
    glfwPollEvents();

    glClear(GL_COLOR_BUFFER_BIT);
    return 1;
}

void Graphics::line(float x1, float y1, float x2, float y2) const {
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
}

const ICanvas &Graphics::getCanvas() const {
    return *this;
}

const Graphics& Graphics::getInstance() {
    static Graphics _instance;
    return _instance;
}