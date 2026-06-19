#include <iostream>
#include <vector>
#include <string>
#include <memory>

// ---------------------------------------------------------
// Struttura Base
// ---------------------------------------------------------
struct Employee {
    std::string name;
    Employee(std::string n) : name(n) { std::cout << "Assunto: " << name << "\n"; }
    ~Employee() { std::cout << "Uscito dall'azienda: " << name << "\n"; }
};

// ---------------------------------------------------------
// ---------------------------------------------------------
// Scrivi una funzione standalone chiamata 'printEmployeeBadge'.
// Deve accettare un Employee, stamparne il nome, NON deve fare copie
// in memoria e NON deve avere i permessi per modificarlo.

void printEmployeeBadge(const Employee& e) {
    std::cout << "Nome: " << e.name;
}


// ---------------------------------------------------------
// Classe Task
// ---------------------------------------------------------
class Task {
private:
    std::string description;

    // Dichiara qui un puntatore al dipendente assegnato (Employee).
    // Ricorda: il Task NON possiede il dipendente e deve evitare reference cycles.
    // -> SCRIVI QUI LA VARIABILE <-
    std::weak_ptr<Employee> dipendente;

public:
    Task(std::string desc) : description(desc) {}

    // Implementa il metodo 'assignEmployee'. Che tipo di parametro deve ricevere
    void assignEmployee(const std::shared_ptr<Employee>& nuovo) {
        dipendente = nuovo;
    }

    void printTaskDetails() const {
        std::cout << "Task: " << description << " - Assegnato a: ";
        // Controlla se il dipendente esiste ancora in memoria.
        // Se esiste, stampa il suo nome. Se è stato distrutto, stampa "Nessuno (Dimesso)".
        // Suggerimento: dovrai "promuovere" temporaneamente il tuo puntatore.

        if (const auto ptr = dipendente.lock())
            std::cout << ptr->name << std::endl;
        else
            std::cout << "Nessuno  (dimesso)" << std::endl;
    }
};

// ---------------------------------------------------------
// Classe Project
// ---------------------------------------------------------
class Project {
private:
    std::string title;

    // Un Project POSSIEDE in via del tutto esclusiva i suoi Task.
    // Dichiara un std::vector che contenga gli smart pointer corretti per i Task.
    std::vector<std::unique_ptr<Task>> tasks;

public:
    Project(std::string t) : title(t) {}

    // Implementa 'addTask'. Il metodo deve ricevere uno smart pointer al Task
    // e "rubarne" o trasferirne la proprietà dentro il vettore del progetto.
    void addTask(const std::shared_ptr<Task>& t) {
        tasks.push_back(std::make_unique<Task>(*t));
    }

    void printProject() const {
        std::cout << "\n--- Progetto: " << title << " ---\n";
        // Cicla e stampa i task (supponendo di aver chiamato il vettore 'tasks')
        for (const auto& task : tasks) {
            task->printTaskDetails();
        }
    }
};

// ---------------------------------------------------------
// Main di Test
// ---------------------------------------------------------
int main() {
    // Creiamo due dipendenti condivisi
    std::shared_ptr<Employee> emp1 = std::make_shared<Employee>("Alice");
    std::shared_ptr<Employee> emp2 = std::make_shared<Employee>("Bob");

    std::cout << "Badge Check: ";
    printEmployeeBadge(*emp1); // Scommenta per testare

    // Creiamo un progetto
    Project proj("Rifacimento Sito Web");

    // Creiamo dei task (esclusivi)
    auto task1 = std::make_unique<Task>("Design UI");
    auto task2 = std::make_unique<Task>("Sviluppo Backend");

    task1->assignEmployee(emp1);
    task2->assignEmployee(emp2);

    proj.addTask(std::move(task1));
    proj.addTask(std::move(task2));

    proj.printProject();

    std::cout << "\n[Bob si licenzia...]\n";
    emp2.reset(); // Bob viene distrutto dalla memoria!

    proj.printProject(); // Il task di Bob dovrebbe ora dire "Nessuno (Dimesso)"

    return 0;
}