//
// Created by jarro on 23/06/26.
//

#include "Project.h"

void Project::addTask(std::shared_ptr<Task> task) {
    tasks.push_back(std::move(task));
}

void Project::checkTask(const std::string &n) {

    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i]->getName() == n) {
            tasks[i]->check();
            return;
        }
    }

    throw std::runtime_error("Task not found");
}

int Project::calculateTotalHours() const {

    int total = 0;

    for (const auto& task : tasks) {
        total += task->getHours();
    }

    return total;
}

int Project::calculateAdvancement() const {

    int completedHours = 0;

    for (const auto& task : tasks) {
        if (task->isDone()) {
            completedHours += task->getHours();
        }
    }

    return completedHours * 100 / calculateTotalHours();
}

void Project::taskAdvancement() const {

    int counter = 0;

    for (const auto& task : tasks) {
        if (task->isDone()) {
            counter++;
        }
    }

    std::cout << "Completati " << counter << " task su " << tasks.size() << std::endl;
}

void Project::status() const {

    std::cout << "Total hours: " << calculateTotalHours() << "\nAdvancement: " << calculateAdvancement() << "%" << std::endl;

    taskAdvancement();
}
