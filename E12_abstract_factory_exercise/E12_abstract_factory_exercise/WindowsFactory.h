//
// Created by jarro on 08/06/26.
//

#ifndef E12_ABSTRACT_FACTORY_EXERCISE_WINDOWSFACTORY_H
#define E12_ABSTRACT_FACTORY_EXERCISE_WINDOWSFACTORY_H
#include "WidgetFactory.h"
#include "WindowsButton.h"
#include "WindowsWindow.h"


class WindowsFactory : public WidgetFactory {
public:
    std::unique_ptr<Button> createButton(const std::string& text) override;
    std::unique_ptr<Window> createWindow(const std::string& title) override;
};


#endif //E12_ABSTRACT_FACTORY_EXERCISE_WINDOWSFACTORY_H
