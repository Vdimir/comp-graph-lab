//
// Created by deffe on 19.03.16.
//

#ifndef GRAPH_SHAPE_H
#define GRAPH_SHAPE_H

#include "Canvas.h"
#include "Transform.h"
#include <glm/glm.hpp>
#include <vector>
#include <memory>

#include <iostream>

class IShape: public IDrawable {

public:
    virtual ~IShape(){};
    virtual IShape& operator*=(const glm::mat4& right) = 0;

    void transform(const glm::mat4 &right);
};

class Polygon : public IShape {
    std::vector<glm::vec4> vertices;
public:
    Polygon & addVertex(float x, float y, float z);
    virtual void draw(const ICanvas& canvas) const;
    virtual Polygon& operator*=(const glm::mat4& right);
};

class ShapeCopm : public IShape {
    std::vector<IShape*> shapes;
public:
    ~ShapeCopm();

    ShapeCopm& add(IShape*);
    virtual void draw(const ICanvas& canvas) const;
    virtual ShapeCopm& operator*=(const glm::mat4& right);
};

#endif //GRAPH_SHAPE_H

