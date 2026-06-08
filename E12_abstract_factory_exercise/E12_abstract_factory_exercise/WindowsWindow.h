#ifndef ABSTRACT_FACTORY_WINDOWSWINDOW_H
#define ABSTRACT_FACTORY_WINDOWSWINDOW_H

#include "Window.h"
#include <string>

class WindowsWindow : public Window {
public:
    WindowsWindow(std::string title);
    virtual ~WindowsWindow() {}

    virtual void draw() override;
    virtual void resize() override;

};


#endif //ABSTRACT_FACTORY_WINDOWSWINDOW_H
