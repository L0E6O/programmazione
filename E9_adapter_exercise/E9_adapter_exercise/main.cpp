#include <vector>
#include "Shape.h"
#include "Sprite.h"
#include "Tile.h"
#include "Text.h"

int main() {
    // TODO use smart pointers instead of raw pointers
    std::vector<Shape *> drawingElements;

    Sprite* hero = new Sprite("hero.bmp");
    Sprite* monster = new Sprite("troll.bmp", 150, 300);
    Tile* floor = new Tile("map_tiles.bmp", 0);
    Tile* wall = new Tile("map_tiles.bmp");

    drawingElements.push_back(hero);
    drawingElements.push_back(monster);
    drawingElements.push_back(wall);
    drawingElements.push_back(floor);

    Text hitPoints("HP: ", 12);
    // TODO add a text reporting "Level: " with font size 14
    // add text to drawingElements

    for (auto drawing_element: (drawingElements) ) {
        drawing_element->resize(1.2);
        drawing_element->draw();
    }

    return 0;
}