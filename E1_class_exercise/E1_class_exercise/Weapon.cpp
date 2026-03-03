#include "Weapon.h"


int Weapon::use() {
    return magic ? strength*2 : strength; // XXX overflow risk
}