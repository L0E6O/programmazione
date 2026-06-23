//
// Created by jarro on 23/06/26.
//

#ifndef OBSERVER_MODIFIEDFLAG_H
#define OBSERVER_MODIFIEDFLAG_H
#include <iostream>
#include <ostream>

#include "Observer.h"

class ModifiedFlag : public Observer {
public:
    ModifiedFlag(TextDocument* s) : Observer(s) {}

    void update() const override;
};


#endif //OBSERVER_MODIFIEDFLAG_H
