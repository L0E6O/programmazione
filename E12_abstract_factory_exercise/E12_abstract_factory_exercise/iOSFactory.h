//
// Created by jarro on 08/06/26.
//

#ifndef E12_ABSTRACT_FACTORY_EXERCISE_IOSFACTORY_H
#define E12_ABSTRACT_FACTORY_EXERCISE_IOSFACTORY_H
#include "WidgetFactory.h"
#include "iOSButton.h"
#include "iOSWindow.h"


class iOSFactory : public WidgetFactory {
    std::unique_ptr<Button> createButton(const std::string& text) override;
    std::unique_ptr<Window> createWindow(const std::string& title) override;
};


#endif //E12_ABSTRACT_FACTORY_EXERCISE_IOSFACTORY_H
