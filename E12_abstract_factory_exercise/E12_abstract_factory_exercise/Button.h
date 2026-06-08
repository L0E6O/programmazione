#ifndef ABSTRACT_FACTORY_BUTTON_H
#define ABSTRACT_FACTORY_BUTTON_H

#include "Widget.h"
#include <string>

class Button : public Widget {
public:
    Button() : text("") {}
    virtual ~Button() {};

    virtual void setIcon() = 0;

    std::string text;
};
#endif //ABSTRACT_FACTORY_BUTTON_H
