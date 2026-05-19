#include "Text.h"
#include <iostream>

void Text::print() {
    std::cout << "font size: " << fontSize << " - Text: " << text << std::endl;
}

void Text::resize(int newSize) {
    fontSize += newSize;
}
