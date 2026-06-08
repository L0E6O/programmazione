#ifndef ABSTRACT_FACTORY_IOSWINDOW_H
#define ABSTRACT_FACTORY_IOSWINDOW_H

#include "Window.h"
#include <iostream>

class iOSWindow : public Window {
public:
    iOSWindow(std::string title);
    virtual ~iOSWindow() {}

    virtual void draw() override;
    virtual void resize() override;

};


#endif //ABSTRACT_FACTORY_IOSWINDOW_H
