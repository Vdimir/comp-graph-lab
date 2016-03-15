
#include "Graphics.h"


int main (int argc, char **argv) {
    Canvas canvas;
    canvas.addLine(0.0f, 0.0f , 1.0f , 1.0f)
            .addLine(0.5f, 0.0f , 1.0f , 1.0f)
            .addLine(-0.5f, 0.0f , 1.0f , 1.0f);

    while(Graphics::getInstance().update(canvas)) { }

    return 0;
}

