//
// Created by Marco Bertini on 08/04/18.
//

#include "Bow.h"

int Bow::use() {
    int result = 0;
    if (arrows-- > 0) {
        result = Weapon::use();
    }
    return result;
}
