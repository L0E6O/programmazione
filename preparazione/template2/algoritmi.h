#ifndef ALGORITMI_H
#define ALGORITMI_H

// ===========================================================
// ESERCIZIO (riscaldamento): funzione template trovaMassimo
// ===========================================================
// Scrivi una funzione template che, dato un array di n elementi
// di tipo generico T, ritorni il valore massimo presente.
// Puoi assumere che T supporti l'operatore di confronto >
// (Persona, nel file persona.h, lo implementa apposta).
// ===========================================================

template <typename T>
T trovaMassimo(const T arr[], int n) {
    // TODO: implementa la ricerca del massimo
    // Riga sotto solo per far compilare lo scheletro, da rimuovere
    T max = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

#endif
