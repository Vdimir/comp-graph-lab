//
// Created by deffe on 15.03.16.
//

#include "Canvas.h"

Canvas::Canvas() {
}

Canvas::~Canvas() {
}

Canvas &Canvas::addLine(Line<Canvas::coord> line) {
    this->_lines.push_back(line);
    return *this;
}

void Canvas::draw() const {
    glClearColor(1, 1, 1, 1);
    glColor3f(0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);

    for (auto v = _lines.begin(); v != _lines.end(); v++) {
        glVertex2f(v->start.x, v->start.y);
        glVertex2f(v->end.x, v->end.y);
    }

    glEnd();

    glfwSwapBuffers();
}

Canvas &Canvas::addLine(Canvas::coord x1, Canvas::coord y1, Canvas::coord x2, Canvas::coord y2) {
    return this->addLine(Line<coord>(x1, y1, x2, y2));
}
