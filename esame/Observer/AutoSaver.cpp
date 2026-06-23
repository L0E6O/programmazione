//
// Created by jarro on 23/06/26.
//

#include "AutoSaver.h"

void Autosaver::update() const {
    if (++counter % 3 == 0)
        std::cout << "Saved!" << std::endl;
}
