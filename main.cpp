
#include "Graphics.h"
#include "Shape.h"

#include <fstream>
#include <string>
#include <sstream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

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

    glm::mat4 Model;
    Model[0] = glm::vec4(2/2.44, 0.0, 0.0, 0.0);
    Model[1] = glm::vec4(-1/2.44, 1/1.41, 0.0, 0.0);
    Model[2] = glm::vec4(-1/1.73, -1/1.41, 0, 0.0);
    Model[3] = glm::vec4(0.0, 0.0, 0.0, 1.0);

    auto shape = loadShapeFromFile("shape.txt");
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

