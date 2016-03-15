//
// Created by deffe on 15.03.16.
//

#ifndef GRAPH_PRIMIRIVES_H
#define GRAPH_PRIMIRIVES_H

template<typename T>
struct Vec2 {
    T x;
    T y;
    Vec2(T _x, T _y) : x(_x), y(_y) {}
};

template<typename T>
struct Line {
    Vec2<T> start;
    Vec2<T> end;

    Line(Vec2<T> s, Vec2<T> e) : start(s), end(e) {}

    Line(T x1, T y1, T x2, T y2) : start(Vec2<T>(x1, y1)),
                                   end(Vec2<T>(x2, y2)) {}
};

#endif //GRAPH_PRIMIRIVES_H
