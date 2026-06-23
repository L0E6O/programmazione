#include <memory>

#include "Project.h"
#include "State.h"
#include "Task.h"

int main() {

    Project p;

    p.addTask(std::make_shared<Task>("Analisi", 10, State::Todo));

    p.addTask(std::make_shared<Task>("Implementazione", 20, State::Todo));

    p.addTask(std::make_shared<Task>("Testing", 5, State::Todo));

    p.checkTask("Analisi");
    p.checkTask("Testing");

    p.status();

    return 0;
}
