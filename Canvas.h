//
// Created by deffe on 15.03.16.
//

#ifndef GRAPH_CANVAS_H
#define GRAPH_CANVAS_H

class ICanvas {
public:
    virtual void line(float x1, float y1, float x2, float y2 ) const = 0;
};

class IDrawable {
public:
    virtual void draw(const ICanvas& canvas) const = 0;
};


#endif //GRAPH_CANVAS_H
