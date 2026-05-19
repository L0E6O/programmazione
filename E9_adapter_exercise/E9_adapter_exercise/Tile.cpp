#include "Tile.h"
#include <iostream>

void Tile::draw() {
    std::cout << "Tile type: " << type << " - dim: " << dim << std::endl;
}

void Tile::resize(float newSize) {
    dim *= newSize;
}
