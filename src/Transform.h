//
// Created by deffe on 20.03.16.
//

#ifndef GRAPH_TRANSFORM_H
#define GRAPH_TRANSFORM_H

#include <glm/glm.hpp>


inline glm::mat4 rotZmat(float angle) {
    glm::mat4 m;
    auto c = std::cos(angle);
    auto s = std::sin(angle);
    m[0] = glm::vec4(c, s, 0, 0);
    m[1] = glm::vec4(-s, c, 0, 0);
    m[2] = glm::vec4(0, 0, 1, 0);
    m[3] = glm::vec4(0, 0, 0, 1);
    return m;
}

inline glm::mat4 rotYmat(float angle) {
    glm::mat4 m;
    auto c = std::cos(angle);
    auto s = std::sin(angle);
    m[0] = glm::vec4(c, 0, -s, 0);
    m[1] = glm::vec4(0, 1, 0, 0);
    m[2] = glm::vec4(s, 0, c, 0);
    m[3] = glm::vec4(0, 0, 0, 1);
    return m;
}

inline glm::mat4 rotXmat(float angle) {
    glm::mat4 m;
    auto c = std::cos(angle);
    auto s = std::sin(angle);
    m[0] = glm::vec4(1, 0, 0, 0);
    m[1] = glm::vec4(0, c, s, 0);
    m[2] = glm::vec4(0, -s, c, 0);
    m[3] = glm::vec4(0, 0, 0, 1);
    return m;
}

inline glm::mat4 scaleMat(float ratioX = 1, float ratioY = 1,float ratioZ = 1) {
    glm::mat4 m;
    m[0] = glm::vec4(ratioX, 0, 0, 0);
    m[1] = glm::vec4(0, ratioY, 0, 0);
    m[2] = glm::vec4(0, 0, ratioZ, 0);
    return m;
}

inline glm::mat4 moveMat(float distX = 0, float distY = 0, float distZ = 0) {
    glm::mat4 m;
    m[3] = glm::vec4(distX, distY, distZ, 1);
    return m;
}


inline glm::mat4 perspectiveMat(float p=0, float q=0, float r=0) {
    glm::mat4 m;
    m[0] = glm::vec4(1, 0, 0, p);
    m[1] = glm::vec4(0, 1, 0, q);
    m[2] = glm::vec4(0, 0, 1, r);
    m[3] = glm::vec4(0, 0, 0, 1);
    return m;
}


inline glm::mat4 obliqueMat(float f, float a) {
    glm::mat4 m;
    m[0] = glm::vec4(1, 0, 0, 0);
    m[1] = glm::vec4(0, 1, 0, 0);
    m[2] = glm::vec4(-f*cos(a), f*sin(a), 1, 0);
    m[3] = glm::vec4(0, 0, 0, 1);
    return m;
}

class TransfromMatrixBuilder {
    glm::mat4 matrix;
public:
    TransfromMatrixBuilder() {}

    TransfromMatrixBuilder& rotateZ(float angle) {
        this->matrix *= rotZmat(angle);
        return *this;
    }

    TransfromMatrixBuilder& rotateY(float angle) {
        this->matrix *= rotYmat(angle);
        return *this;
    }

    TransfromMatrixBuilder& rotateX(float angle) {
        this->matrix *= rotXmat(angle);
        return *this;
    }

    TransfromMatrixBuilder& scaleX(float angle) {
        this->matrix *= scaleMat(angle, 1 ,1);
        return *this;
    }

    TransfromMatrixBuilder& scaleY(float angle) {
        this->matrix *= scaleMat(1, angle, 1);
        return *this;
    }

    TransfromMatrixBuilder& scaleZ(float angle) {
        this->matrix *= scaleMat(1, 1, angle);
        return *this;
    }

    TransfromMatrixBuilder& moveX(float distance) {
        this->matrix *= moveMat(distance, 0 ,0);
        return *this;
    }

    TransfromMatrixBuilder& moveY(float distance) {
        this->matrix *= moveMat(0, distance, 0);
        return *this;
    }

    TransfromMatrixBuilder& moveZ(float distance) {
        this->matrix *= moveMat(0, 0, distance);
        return *this;
    }

    TransfromMatrixBuilder& perspectiveZ(float r) {
        this->matrix *= perspectiveMat(0,0,r);
        return *this;
    }

    TransfromMatrixBuilder& perspectiveY(float q) {
        this->matrix *= perspectiveMat(0,q,0);
        return *this;
    }

    TransfromMatrixBuilder& perspectiveX(float p) {
        this->matrix *= perspectiveMat(p,0,0);
        return *this;
    }


    TransfromMatrixBuilder& obliq(float f, float a) {
        this->matrix *= obliqueMat(f, a);
        return *this;
    }

    glm::mat4 getMat() {
        return matrix;
    }
};

#define PI 3.1415f

glm::mat4 getPreset1();
glm::mat4 getPreset2();
glm::mat4 getPreset3();
glm::mat4 getPreset4();
glm::mat4 getPreset5();
glm::mat4 getPreset6();
glm::mat4 getPreset7();
glm::mat4 getPreset8();
glm::mat4 getPreset9();
glm::mat4 getPreset10();
glm::mat4 getPreset11();
#endif //GRAPH_TRANSFORM_H
