# C++ Debugging Lab (didattico)

Obiettivo: imparare il debugging *pratico* con breakpoint, step, watch, call stack e ispezione di variabili/memoria.

Il programma **compila** e **gira**, ma produce risultati **sbagliati** a causa di bug intenzionali.

## Requisiti
- CMake >= 3.16
- Un compilatore C++17 (GCC/Clang/MSVC)

## Build & run
```bash
cmake -S . -B build
cmake --build build
./build/debugging_lab
```

Output atteso: vedrai una serie di test `FAIL`. L'obiettivo è farli diventare `PASS` correggendo i bug.

## I 3 bug (almeno) da trovare
1) **Pointer sbagliato / pointer arithmetic**
2) **Off-by-one**
3) **Magic number**

(Extra: ci sono piccoli "smell" che puoi migliorare, ma non sono richiesti.)

## Workflow consigliato
Vedi `scripts/lab_script.md`.
