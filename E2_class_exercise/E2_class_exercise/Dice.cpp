//
// Created by Marco Bertini on 21/03/18.
//

#include "Dice.h"

#include <cstdlib> // for rand and srand

int Dice::rollsNum = 0;
// read: https://stackoverflow.com/questions/7343833/srand-why-call-it-only-once -- riguardo sRand


int Dice::roll(int r) {
    int result=0;
    if (rollsNum >= MAX_ROLLS) {
        srand(time(0));
        rollsNum = 0;
    }
    // XXX it goes against the best practice. Set a very high number for max num rolls
    // read: https://stackoverflow.com/questions/1452934/what-is-the-meaning-of-xxx-in-code-comments

    for (int i=0; i<r; i++) {
        result += rand() % faces;
        rollsNum++;
    }
    return result;
}