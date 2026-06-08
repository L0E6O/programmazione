#include "iOSWindow.h"
#include <iostream>

iOSWindow::iOSWindow(std::string title) {
    this->title = title;
}

void iOSWindow::draw() {
    std::cout << "iOS Window: " << title << std::endl;
}

void iOSWindow::resize() {
    std::cout << "iOS Window resize" << std::endl;
}
