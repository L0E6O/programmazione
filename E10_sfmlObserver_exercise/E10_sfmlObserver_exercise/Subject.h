#ifndef OBSERVER_SUBJECT_H
#define OBSERVER_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual void subscribe(Observer* observer) = 0;
    virtual void unsubscribe() = 0;

    virtual void notify() = 0;
};

#endif //OBSERVER_SUBJECT_H
