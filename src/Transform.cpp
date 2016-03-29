#include "Transform.h"
glm::mat4 getPreset1() {
    return TransfromMatrixBuilder()
            .moveX(-1.0f)
            .moveY(0.5f)
            .scaleX(0.4f)
            .scaleY(0.4f)
            .scaleZ(0.4f)
            .getMat();
}

glm::mat4 getPreset2() {
    return TransfromMatrixBuilder()
            .moveX(-0.6f)
            .moveY(0.6f)
            .rotateX(PI/2)
            .scaleX(0.4f)
            .scaleY(0.4f)
            .scaleZ(0.4f)
            .getMat();
}

glm::mat4 getPreset3() {
    return TransfromMatrixBuilder()
            .moveX(-0.2f)
            .moveY(0.5f)
            .scaleX(0.4f)
            .scaleY(0.4f)
            .scaleZ(0.4f)
            .rotateX(-PI/4)
            .rotateY(PI/4)
            .getMat();
}


glm::mat4 getPreset4() {
    return TransfromMatrixBuilder()
            .moveX(0.2f)
            .moveY(0.5f)
            .scaleX(0.4f)
            .scaleY(0.4f)
            .scaleZ(0.4f)
            .rotateX(-PI/6)
            .rotateY(PI/4)
            .getMat();
}


glm::mat4 getPreset5() {
    return TransfromMatrixBuilder()
            .moveX(0.6f)
            .moveY(0.5f)
            .scaleX(0.4f)
            .scaleY(0.4f)
            .scaleZ(0.4f)
            .rotateX(-PI/10)
            .rotateY(PI/4)
            .getMat();
}


glm::mat4 getPreset6() {
    return TransfromMatrixBuilder()
            .moveX(-1.0f)
            .moveY(0.0f)
            .scaleX(0.4f)
            .scaleY(0.4f)
            .scaleZ(0.4f)
            .perspectiveX(0.3f)
            .rotateX(-PI/6)
            .rotateY(PI/4)
            .getMat();
}


glm::mat4 getPreset7() {
    return TransfromMatrixBuilder()
            .moveX(-0.6f)
            .moveY(0.0f)
            .scaleX(0.4f)
            .scaleY(0.4f)
            .scaleZ(0.4f)
            .perspectiveX(0.4f)
            .rotateX(-PI/6)
            .rotateY(PI/4)
            .getMat();
}

glm::mat4 getPreset8() {
    return TransfromMatrixBuilder()
            .moveX(-0.2f)
            .moveY(0.0f)
            .scaleX(0.4f)
            .scaleY(0.4f)
            .scaleZ(0.4f)
            .perspectiveY(0.4f)
            .perspectiveZ(0.4f)
            .rotateX(-PI/6)
            .rotateY(PI/4)
            .getMat();
}


glm::mat4 getPreset9() {
    return TransfromMatrixBuilder()
            .moveX(0.2f)
            .moveY(0.0f)
            .scaleX(0.4f)
            .scaleY(0.4f)
            .scaleZ(0.4f)
            .obliq(0.6, PI/6)
            .rotateX(-PI/6)
            .rotateY(PI/4)
            .getMat();
}


glm::mat4 getPreset10() {
    return TransfromMatrixBuilder()
            .moveX(-0.2f)
            .moveY(-0.6f)
            .scaleX(-0.4f)
            .scaleY(0.4f)
            .scaleZ(0.4f)
            .obliq(0.8, PI/6)
            .rotateX(-PI/6)
            .rotateY(PI/4)
            .getMat();
}

glm::mat4 getPreset11() {
    return TransfromMatrixBuilder()
            .moveX(-0.0f)
            .moveY(-0.6f)
            .scaleX(0.4f)
            .scaleY(0.4f)
            .scaleZ(0.4f)
            .obliq(0.8, PI/4)
            .rotateX(-PI/6)
            .rotateY(PI/4)
            .getMat();
}