#include "WindowsWindow.h"
#include <iostream>

WindowsWindow::WindowsWindow(std::string title) {
    this->title = title;
}

void WindowsWindow::draw() {
    std::cout << "WinWindow: " << title << std::endl;
}

void WindowsWindow::resize() {
    std::cout << "Windows Window resize" << std::endl;
}
