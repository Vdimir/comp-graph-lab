
#include "Graphics.h"
#include "Shape.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

IShape* myShape() {
    auto bottom = new Polygon();
    bottom->addVertex(0.0, 0.0, 0.0)
            .addVertex(0.9, 0.0, 0.0)
            .addVertex(0.9, 0.9, 0.0)
            .addVertex(0.0, 0.9, 0.0);


    auto top = new Polygon();
    top->addVertex(0.0, 0.0, 1.0)
            .addVertex(0.9, 0.0, 1.0)
            .addVertex(0.9, 0.9, 1.0)
            .addVertex(0.0, 0.9, 1.0);

    ShapeCopm* shape = new ShapeCopm();
    shape->add(top).add(bottom);
    return shape;
}

void displayLoop()
{

    glm::mat4 Model;
    Model[0] = glm::vec4(2/2.44, 0.0, 0.0, 0.0);
    Model[1] = glm::vec4(-1/2.44, 1/1.41, 0.0, 0.0);
    Model[2] = glm::vec4(-1/1.73, -1/1.41, 0, 0.0);
    Model[3] = glm::vec4(0.0, 0.0, 0.0, 1.0);

    auto shape = myShape();
    *shape *= Model;

    const Graphics& scene = Graphics::getInstance();

    while(scene.update()) {
        shape->draw(scene.getCanvas());
    }

    delete shape;
}

int main (int argc, char **argv) {
    displayLoop();

    std::cout << "Done";

    return 0;
}

