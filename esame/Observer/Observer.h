//
// Created by jarro on 23/06/26.
//

#ifndef OBSERVER_OBSERVER_H
#define OBSERVER_OBSERVER_H


class TextDocument;

class Observer {
public:
    Observer(TextDocument* s) : subject(s) {}

    virtual ~Observer() = default;

    virtual void update() const = 0;

protected:
    TextDocument* subject;
};


#endif //OBSERVER_OBSERVER_H
