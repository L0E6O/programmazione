#ifndef PILA_H
#define PILA_H

#include <stdexcept>
#include <iostream>

// ===========================================================
// ESERCIZIO: Pila generica a capacita' fissa (Pila<T, Capacita>)
// ===========================================================
// Completa le parti contrassegnate con TODO.
// La classe deve implementare una pila (stack) LIFO che usa
// un array statico di dimensione Capacita (parametro template
// NON di tipo, con valore di default 10).
//
// Metodi richiesti:
//  - push(const T& elemento): inserisce un elemento in cima.
//      Se la pila e' piena, lancia std::overflow_error("Pila piena").
//  - pop(): rimuove l'elemento in cima.
//      Se la pila e' vuota, lancia std::underflow_error("Pila vuota").
//  - top() const: ritorna (senza rimuovere) l'elemento in cima.
//      Se la pila e' vuota, lancia std::underflow_error("Pila vuota").
//  - vuota() const: ritorna true se la pila non contiene elementi.
//  - piena() const: ritorna true se la pila ha raggiunto Capacita.
//  - dimensione() const: ritorna il numero di elementi presenti.
//
// In piu', va completato l'operatore di stampa (operator<<),
// dichiarato come funzione friend template, che stampa gli
// elementi dal fondo alla cima separati da uno spazio.
// (Le definizioni dei metodi sono dentro la classe per semplicita',
//  essendo template; in un progetto reale spesso si separano
//  dichiarazione/definizione ma il risultato e' lo stesso.)
// ===========================================================

template <typename T, int Capacita = 10>
class Pila {
private:
    T dati[Capacita];
    int numElementi; // numero di elementi attualmente presenti

public:
    Pila() : numElementi(0) {}

    void push(const T& elemento) {
        if (numElementi == Capacita)
            throw std::overflow_error("pila piena");
        dati[numElementi++] = elemento;
    }

    void pop() {
        if (numElementi > 0)
            numElementi--;
        else
            throw std::underflow_error("pila vuota");
    }

    T top() const {
        return dati[numElementi-1];
    }

    bool vuota() const {
        return numElementi == 0;
    }

    bool piena() const {
        return numElementi==Capacita;
    }

    int dimensione() const {
        return numElementi;
    }

    template <typename U, int C>
    friend std::ostream& operator<<(std::ostream& os, const Pila<U, C>& pila);
};

template <typename T, int Capacita>
std::ostream& operator<<(std::ostream& os, const Pila<T, Capacita>& pila) {
    for (int i = 0; i < pila.numElementi; i++) {
        os << pila.dati[i] << (i == pila.numElementi-1 ? "\n" : " ");
    }
    return os;
}

#endif
