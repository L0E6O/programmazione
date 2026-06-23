//
// Created by jarro on 23/06/26.
//

#ifndef OBSERVER_AUTOSAVER_H
#define OBSERVER_AUTOSAVER_H
#include <iostream>
#include <ostream>

#include "Observer.h"


class Autosaver : public Observer {
public:
    Autosaver(TextDocument* s) : Observer(s) {}

    void update() const override;

private:
    mutable int counter = 0;
};


#endif //OBSERVER_AUTOSAVER_H
