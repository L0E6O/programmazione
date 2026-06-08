//
// Created by jarro on 08/06/26.
//

#include "WindowsFactory.h"

std::unique_ptr<Button> WindowsFactory::createButton(const std::string &text) {
    return std::make_unique<WindowsButton>(text);
}

std::unique_ptr<Window> WindowsFactory::createWindow(const std::string &title) {
    return std::make_unique<WindowsWindow>(title);
}