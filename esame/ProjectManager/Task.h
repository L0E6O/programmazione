//
// Created by jarro on 23/06/26.
//

#ifndef PROJECTMANAGER_TASK_H
#define PROJECTMANAGER_TASK_H
#include <string>

#include "State.h"


class Task {
public:
    Task(std::string n, const int h, const State s) : name(std::move(n)), hours(h), taskState(s) {}

    std::string getName() const {
        return name;
    }

    void check() {
        taskState = State::Done;
    }

    int getHours() const {
        return hours;
    }

    bool isDone() const {
        return taskState == State::Done;
    }

private:
    std::string name;
    int hours;
    State taskState;
};


#endif //PROJECTMANAGER_TASK_H
