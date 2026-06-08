#include "WindowsButton.h"
#include <iostream>

WindowsButton::WindowsButton(std::string text) {
    this->text = text;
}

void WindowsButton::draw() {
    std::cout << "WinButton: " << text << std::endl;
}

void WindowsButton::setIcon() {
    std::cout << "set large Windows icon" << std::endl;
}
