//
// Created by deffe on 15.03.16.
//

#ifndef GRAPH_CANVAS_H
#define GRAPH_CANVAS_H

#include <vector>

#include <GL/glfw.h>
#include "Primirives.h"

class Canvas {
    typedef float coord;
    std::vector<Line<coord> > _lines;


public:
    Canvas();
    ~Canvas();

    Canvas& addLine(Line<coord>);
    Canvas& addLine(coord x1, coord y1, coord x2, coord y2);

    void draw() const;

};


#endif //GRAPH_CANVAS_H
