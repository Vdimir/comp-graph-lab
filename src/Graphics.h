//
// Created by deffe on 15.03.16.
//

#ifndef GRAPH_GRAPHICS_H
#define GRAPH_GRAPHICS_H

#include <GLFW/glfw3.h>

#include "Canvas.h"
#include <iostream>
class Graphics: private ICanvas {
    GLFWwindow* window = 0;

    Graphics();
    ~Graphics();

    virtual void line(float x1, float y1, float x2, float y2 ) const;
public:

    int update() const;
    const ICanvas& getCanvas() const;
    static const Graphics& getInstance();
};

#endif //GRAPH_GRAPHICS_H
