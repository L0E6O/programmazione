#include "Sprite.h"
#include <iostream>

void Sprite::draw() {
    std::cout << "Draw sprite: " << fileName <<
            " - w: " << width << " - h: " << height << std::endl;
}

void Sprite::resize(float newSize) {
    width *= newSize;
    height *= newSize;
}
