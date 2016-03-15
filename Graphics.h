//
// Created by deffe on 15.03.16.
//

#ifndef GRAPH_GRAPHICS_H
#define GRAPH_GRAPHICS_H

#include <GL/glfw.h>

#include "Canvas.h"
#include <iostream>
class Graphics {


    Graphics();
    ~Graphics();

    bool isWindowOpened() const;

public:
    int update(Canvas &) const;
    static const Graphics& getInstance();
};


#endif //GRAPH_GRAPHICS_H
