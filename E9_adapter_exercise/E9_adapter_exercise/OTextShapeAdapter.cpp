//
// Created by jarro on 19/05/26.
//

#include <iostream>

#include "OTextShapeAdapter.h"
#include "Text.h"

void OTextShapeAdapter::draw() {
    adaptee.print();
}

void OTextShapeAdapter::resize(float f) {
    int delta = adaptee.getFontSize()*f - adaptee.getFontSize();
    adaptee.resize(delta);
}