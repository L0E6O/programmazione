//
// Created by jarro on 19/05/26.
//

#include "TextShapeAdapter.h"

void TextShapeAdapter::draw() {
    print();
}

void TextShapeAdapter::resize(float f) {
    int delta = fontSize*f - fontSize;
    Text::resize(delta);
}