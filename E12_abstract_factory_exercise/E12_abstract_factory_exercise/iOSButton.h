#ifndef ABSTRACT_FACTORY_IOSBUTTON_H
#define ABSTRACT_FACTORY_IOSBUTTON_H

#include "Button.h"
#include <string>

class iOSButton : public Button {
public:
    iOSButton(std::string text);
    virtual ~iOSButton() {}

    virtual void draw() override;
    virtual void setIcon() override;

};


#endif //ABSTRACT_FACTORY_IOSBUTTON_H
