//
// Created by jarro on 23/06/26.
//

#ifndef OBSERVER_WORDCOUNTSTATUS_H
#define OBSERVER_WORDCOUNTSTATUS_H
#include <iostream>
#include <ostream>

#include "Observer.h"

class WordCountStatus : public Observer {
public:
    WordCountStatus(TextDocument* s) : Observer(s) {}

    void update() const override;
};


#endif //OBSERVER_WORDCOUNTSTATUS_H
