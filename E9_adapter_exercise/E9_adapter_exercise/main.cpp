#include <memory>
#include <vector>

#include "OTextShapeAdapter.h"
#include "Shape.h"
#include "Sprite.h"
#include "Tile.h"
#include "Text.h"
#include "TextShapeAdapter.h"

int main() {
    // TODO use smart pointers instead of raw pointers
    std::vector<std::unique_ptr<Shape>> drawingElements;

    std::unique_ptr<Shape> hero (new Sprite("hero.bmp"));
    std::unique_ptr<Shape> monster(new Sprite("troll.bmp", 150, 300));
    std::unique_ptr<Shape> floor(new Tile("map_tiles.bmp", 0));
    std::unique_ptr<Shape> wall(new Tile("map_tiles.bmp"));

    drawingElements.push_back(std::move(hero));
    drawingElements.push_back(std::move(monster));
    drawingElements.push_back(std::move(wall));
    drawingElements.push_back(std::move(floor));

    Text hitPoints("HP: ", 12);
    std::unique_ptr<Shape> hitPointsAdapter(new TextShapeAdapter(hitPoints));
    drawingElements.push_back(std::move(hitPointsAdapter));
    Text Level("Level: ", 14);
    std::unique_ptr<Shape> LevelAdapter(new OTextShapeAdapter(Level));
    drawingElements.push_back(std::move(LevelAdapter));

    for (auto it = begin(drawingElements); it != end(drawingElements); ++it) {
        (*it)->resize(1.2);
        (*it)->draw();
    }

    return 0;
}
