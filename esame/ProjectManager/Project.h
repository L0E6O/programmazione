//
// Created by jarro on 23/06/26.
//

#ifndef PROJECTMANAGER_PROJECT_H
#define PROJECTMANAGER_PROJECT_H


#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>

#include "Task.h"

class Project {
public:
    void addTask(std::shared_ptr<Task> task);

    void checkTask(const std::string& n);

    int calculateTotalHours() const;

    int calculateAdvancement() const;

    void taskAdvancement() const;

    void status() const;

private:
    std::vector<std::shared_ptr<Task>> tasks;
};


#endif //PROJECTMANAGER_PROJECT_H
