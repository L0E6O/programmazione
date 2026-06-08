#ifndef ABSTRACT_FACTORY_WINDOW_H
#define ABSTRACT_FACTORY_WINDOW_H

#include "Widget.h"
#include <string>

class Window : public Widget {
public:
    Window() : title("") {}
    virtual ~Window() {}

    virtual void resize() = 0;

    std::string title;
};
#endif //ABSTRACT_FACTORY_WINDOW_H
