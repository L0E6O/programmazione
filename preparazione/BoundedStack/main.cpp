#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

// ---------------------------------------------------------
// TODO 1: Eccezioni Personalizzate
// ---------------------------------------------------------
// Crea due classi: 'StackOverflowError' e 'StackEmptyError'.
// Entrambe devono ereditare pubblicamente da 'std::runtime_error'.
// Implementa i costruttori in modo che passino un messaggio di
// errore appropriato alla classe base.

// -> SCRIVI QUI LE DUE CLASSI ECCEZIONE <-
class StackOverflowError : public std::runtime_error {
public:
    StackOverflowError(const std::string& s) : runtime_error(s) {} // XXX PERCHÈ NON VA BENE IL MOVE? => LE ECCEZIONI NON HANNO COSTRUTTORI MOVE (PER EVITARE ECCEZIONI)
};

class StackEmptyError : public std::runtime_error {
public:
    StackEmptyError(const std::string& s) : runtime_error(s) {}
};


// ---------------------------------------------------------
// TODO 2: La Classe Template
// ---------------------------------------------------------
// Dichiara una classe 'SafeStack' che accetti un parametro di tipo 'T' (Template).
// Deve contenere:
// 1. Un std::vector<T> (dalla STL) per memorizzare i dati.
// 2. Un 'size_t max_capacity' per il limite massimo.
// 3. Un costruttore che inizializzi la capacità massima.

// -> INIZIA LA CLASSE SafeStack QUI <-
template <typename T>
class SafeStack {
public:
    SafeStack(size_t m) : max_capacity(m) {}

    void push(const T& value) {
        if (data.size() == max_capacity)
            throw StackOverflowError("Stack full");
        data.push_back(value);
    }

    T pop() {
        if (data.size() == 0)
            throw StackEmptyError("Stack vuoto");
        T popped = data.back();
        data.pop_back();
        return popped;
    }
private:
    std::vector<T> data;
    size_t max_capacity;
};

    // ---------------------------------------------------------
    // TODO 3: Il metodo Push
    // ---------------------------------------------------------
    // Implementa 'void push(const T& value)'.
    // Se la grandezza attuale del vettore è uguale o maggiore della
    // capacità massima, lancia un 'StackOverflowError'.
    // Altrimenti, usa i metodi della STL per aggiungere l'elemento al vettore.

    // ---------------------------------------------------------
    // TODO 4: Il metodo Pop
    // ---------------------------------------------------------
    // Implementa 'T pop()'.
    // Se il vettore è vuoto, lancia un 'StackEmptyError'.
    // Altrimenti, salva l'ultimo elemento, rimuovilo dal vettore
    // usando i metodi della STL, e restituiscilo.


// ---------------------------------------------------------
// Main di Test (Non modificare)
// ---------------------------------------------------------
int main() {
    /* Scommenta il codice sottostante quando hai completato l'implementazione */


    std::cout << "--- Test con Interi (Capacita' 2) ---\n";
    SafeStack<int> intStack(2);

    try {
        intStack.push(10);
        std::cout << "Pushed: 10\n";
        intStack.push(20);
        std::cout << "Pushed: 20\n";

        // Questo dovrebbe lanciare l'eccezione
        intStack.push(30);
        std::cout << "Pushed: 30\n";
    } catch (const std::exception& e) {
        std::cout << "Errore catturato: " << e.what() << "\n";
    }

    std::cout << "\n--- Test con Stringhe ---\n";
    SafeStack<std::string> stringStack(5);

    try {
        stringStack.push("Hello");
        std::cout << "Pop: " << stringStack.pop() << "\n";

        // Questo dovrebbe lanciare l'eccezione
        std::cout << "Pop: " << stringStack.pop() << "\n";
    } catch (const std::exception& e) {
        std::cout << "Errore catturato: " << e.what() << "\n";
    }


    return 0;
}