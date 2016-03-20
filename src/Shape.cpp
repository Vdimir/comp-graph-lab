//
// Created by deffe on 19.03.16.
//

#include "Shape.h"
#include <algorithm>

Polygon &Polygon::addVertex(float x, float y, float z) {
    this->vertices.push_back(glm::vec4(glm::vec3(x, y, z), 1));
    return *this;
}

void Polygon::draw(const ICanvas &canvas) const {
    auto N = vertices.size();
    for (int i = 0; i < N; ++i) {
        canvas.line(vertices[i].x/vertices[i].w,
                    vertices[i].y/vertices[i].w,
                    vertices[(i+1)%N].x/vertices[(i+1)%N].w,
                    vertices[(i+1)%N].y/vertices[(i+1)%N].w);
    }
}

Polygon &Polygon::operator*=(const glm::mat4& right)
{
    for (auto v = vertices.begin(); v != vertices.end(); v++) {
        *v  = right * (*v);
    }
    return *this;
}


ShapeCopm &ShapeCopm::add(IShape *shape) {
    this->shapes.push_back(shape);
    return *this;
}

void ShapeCopm::draw(const ICanvas &canvas) const {
    std::for_each(shapes.begin(), shapes.end(), [&canvas](IShape* s) {
        s->draw(canvas);
    });
}

ShapeCopm &ShapeCopm::operator*=(const glm::mat4 &right) {
    for (auto v = shapes.begin(); v != shapes.end(); v++) {
        **v  *= right;
    }
    return *this;
}

ShapeCopm::~ShapeCopm() {
    for (auto v = shapes.begin(); v != shapes.end(); v++) {
        delete *v;
    }
    shapes.clear();
}

void IShape::transform(const glm::mat4 &right) {
    *this *= right;
}
