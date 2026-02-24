# Script di laboratorio: Debugging guidato (studenti)

## Setup rapido
1. Compila in modalità Debug:
   - CMake: `cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug` (Linux/macOS)
   - Windows/Visual Studio: seleziona configurazione **Debug**
2. Esegui: `./build/debugging_lab` (o dal tuo IDE).

## Cosa osservare
Il programma stampa una checklist tipo:
- `[PASS] ...`
- `[FAIL] ... (got=..., expected=...)`

**Regola del gioco:** non "fixare a caso". Usa breakpoint, step, watch.

---

# Parte A — Bug #1 (pointer sbagliato / pointer arithmetic)
**Sintomo:** fallisce il test sul *peak temperature* (massimo).

### Obiettivo
Capire perché `findPeakTemperatureC()` non ritorna il massimo vero.


### Criterio di successo
Il test `[PeakTemperature]` deve passare.

---

# Parte B — Bug #2 (off-by-one)
**Sintomo:** fallisce il test sulla *median*.

### Obiettivo
La mediana di un array con 5 elementi deve essere l'elemento centrale dopo sorting.


### Criterio di successo
Il test `[Median]` deve passare.

---

# Parte C — Bug #3 (magic number)
**Sintomo:** fallisce il test `CelsiusToFahrenheit`.

### Obiettivo
La conversione corretta è: `F = C * 9/5 + 32`.

### Criterio di successo
Il test `[CelsiusToFahrenheit]` deve passare.

---

# Bonus (opzionale)
- Attiva warning del compilatore e risolvi i warning (senza cambiare il comportamento, se possibile).