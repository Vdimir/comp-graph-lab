
#include "src/Graphics.h"
#include "src/Shape.h"
#include "src/Transform.h"

#include <fstream>
#include <string>
#include <sstream>

#include <glm/glm.hpp>
#include <memory>

#define PI 3.1415f
IShape* loadShapeFromFile(const char* fname) {
    std::ifstream fin(fname);
    if (!fin.is_open()) {
        throw "error open file";
    }

    ShapeCopm* shape = new ShapeCopm();
    auto poly = new Polygon();
    while (!fin.eof()) {
        std::string line;
        std::getline(fin, line);

        if (line.empty()) {
            shape->add(poly);
            poly = new Polygon();
            continue;
        }

        std::stringstream ss(line);
        float x,y,z;
        ss >> x >> y >> z;
        poly->addVertex(x,y,z);
    }

    fin.close();
    return shape;
}

void displayLoop()
{
    auto shape = std::unique_ptr<IShape>(loadShapeFromFile("resources/shape.txt"));

    const Graphics& scene = Graphics::getInstance();

    shape->transform(TransfromMatrixBuilder()
                         .moveX(-0.5f)
                         .perspectiveX(-0.3f)
                         .perspectiveY(-0.2f)
                         .rotateX(PI / 4.0f)
                         .rotateY(-PI / 4.0f)
                         .scaleZ(0.6f)
                         .getMat());

    while(scene.update()) {
        shape->draw(scene.getCanvas());
    }

}

int main (int argc, char **argv) {

    displayLoop();

    std::cout << "Done";

    return 0;
}

