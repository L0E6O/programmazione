#include "iOSButton.h"
#include <iostream>

iOSButton::iOSButton(std::string text) {
    this->text = text;
}

void iOSButton::draw() {
    std::cout << "iOS Button: " << text << std::endl;
}

void iOSButton::setIcon() {
    std::cout << "set small iOS icon" << std::endl;
}
