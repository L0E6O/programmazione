#ifndef ABSTRACT_FACTORY_WINDOWSBUTTON_H
#define ABSTRACT_FACTORY_WINDOWSBUTTON_H

#include "Button.h"
#include <string>

class WindowsButton : public Button {
public:
    WindowsButton(std::string text);
    virtual ~WindowsButton() {}

    virtual void draw() override;
    virtual void setIcon() override;
};


#endif //ABSTRACT_FACTORY_WINDOWSBUTTON_H
