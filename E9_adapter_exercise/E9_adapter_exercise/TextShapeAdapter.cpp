//
// Created by jarro on 19/05/26.
//

#include "TextShapeAdapter.h"
#include <iostream>

void TextShapeAdapter::draw() {
    std::cout << "Text: " << text << std::endl;
}

void TextShapeAdapter::resize(float f) {
    fontSize = f;
}
