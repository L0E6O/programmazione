#ifndef ABSTRACT_FACTORY_WIDGETFACTORY_H
#define ABSTRACT_FACTORY_WIDGETFACTORY_H

#include <memory>

#include "Button.h"
#include "Window.h"
#include <string>

class WidgetFactory {
public:
    virtual std::unique_ptr<Button> createButton(const std::string& text) = 0;
    virtual std::unique_ptr<Window> createWindow(const std::string& title) = 0;
};

#endif //ABSTRACT_FACTORY_WIDGETFACTORY_H
