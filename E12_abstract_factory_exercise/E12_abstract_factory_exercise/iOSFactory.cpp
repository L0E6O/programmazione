//
// Created by jarro on 08/06/26.
//

#include "iOSFactory.h"

std::unique_ptr<Button> iOSFactory::createButton(const std::string &text) {
    return std::make_unique<iOSButton>(text);
}

std::unique_ptr<Window> iOSFactory::createWindow(const std::string &title) {
    return std::make_unique<iOSWindow>(title);
}
