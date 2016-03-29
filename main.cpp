
#include "src/Graphics.h"
#include "src/Shape.h"
#include "src/Transform.h"

#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include <glm/glm.hpp>
#include <memory>

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
    const Graphics& scene = Graphics::getInstance();

    std::vector<std::unique_ptr<IShape>> shapes;
    for (int i = 0; i < 11; ++i) {
        shapes.push_back(std::unique_ptr<IShape>(loadShapeFromFile("resources/shape.txt")));
    }
    shapes[0]->transform(getPreset1());
    shapes[1]->transform(getPreset2());
    shapes[2]->transform(getPreset3());
    shapes[3]->transform(getPreset4());
    shapes[4]->transform(getPreset5());
    shapes[5]->transform(getPreset6());
    shapes[6]->transform(getPreset7());
    shapes[7]->transform(getPreset8());
    shapes[8]->transform(getPreset9());
    shapes[9]->transform(getPreset10());
    shapes[10]->transform(getPreset11());

    while(scene.update()) {
        for (auto s = shapes.begin(); s != shapes.end(); s++) {
            (*s)->draw(scene.getCanvas());
        }
    }

}

int main (int argc, char **argv) {

    displayLoop();

    std::cout << "Done";

    return 0;
}

