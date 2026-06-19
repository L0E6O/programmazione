#include <iostream>
#include "pila.h"
#include "algoritmi.h"
#include "persona.h"

int main() {
    std::cout << "=== Test funzione template trovaMassimo ===\n";
    int numeri[] = {4, 9, 2, 7, 5};
    std::cout << "Massimo tra interi: " << trovaMassimo(numeri, 5) << "\n";

    double decimali[] = {3.2, 1.5, 9.9, 4.4};
    std::cout << "Massimo tra double: " << trovaMassimo(decimali, 4) << "\n\n";

    std::cout << "=== Test classe template Pila ===\n";
    Pila<int, 5> pilaInteri;
    pilaInteri.push(10);
    pilaInteri.push(20);
    pilaInteri.push(30);
    std::cout << "Pila di interi: " << pilaInteri << "\n";
    std::cout << "Cima: " << pilaInteri.top() << "\n";
    pilaInteri.pop();
    std::cout << "Dopo pop: " << pilaInteri << "\n";
    std::cout << "Dimensione: " << pilaInteri.dimensione() << "\n\n";

    std::cout << "=== Test con tipo personalizzato Persona ===\n";
    Pila<Persona, 3> pilaPersone;
    pilaPersone.push(Persona("Anna", 30));
    pilaPersone.push(Persona("Marco", 25));
    std::cout << "Pila di persone: " << pilaPersone << "\n";

    Persona elenco[] = {Persona("Anna", 30), Persona("Marco", 25), Persona("Luca", 40)};
    std::cout << "Persona piu' anziana: " << trovaMassimo(elenco, 3) << "\n\n";

    std::cout << "=== Test gestione errori ===\n";
    try {
        Pila<int, 2> pilaPiccola;
        pilaPiccola.push(1);
        pilaPiccola.push(2);
        pilaPiccola.push(3); // deve lanciare std::overflow_error
        std::cout << "ERRORE: non e' stata lanciata l'eccezione attesa!\n";
    } catch (const std::overflow_error& e) {
        std::cout << "Eccezione catturata correttamente: " << e.what() << "\n";
    }

    try {
        Pila<int> pilaVuota;
        pilaVuota.pop(); // deve lanciare std::underflow_error
        std::cout << "ERRORE: non e' stata lanciata l'eccezione attesa!\n";
    } catch (const std::underflow_error& e) {
        std::cout << "Eccezione catturata correttamente: " << e.what() << "\n";
    }

    return 0;
}
