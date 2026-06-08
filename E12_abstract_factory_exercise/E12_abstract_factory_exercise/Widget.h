#ifndef ABSTRACT_FACTORY_WIDGET_H
#define ABSTRACT_FACTORY_WIDGET_H

class Widget {
public:
    virtual ~Widget() {}
    virtual void draw() = 0;
};

#endif //ABSTRACT_FACTORY_WIDGET_H
