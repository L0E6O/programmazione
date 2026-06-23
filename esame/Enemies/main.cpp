#include <iostream>
#include <vector>

#include "Dragon.h"
#include "Enemy.h"
#include "Goblin.h"
#include "Ogre.h"

int waveTotalDamage(const std::vector<Enemy*>& enemies) {
    int total = 0;

    for (const auto& enemy : enemies) {
        total += enemy->calculate_damage();
    }

    return total;
}

int main() {

    std::vector<Enemy*> enemies;

    enemies.push_back(new Goblin("Goblin Scout", 15, 5));
    enemies.push_back(new Ogre("Ogre Brute", 8, 10));      // hp < 10 -> danno raddoppiato
    enemies.push_back(new Dragon("Smaug", 100, 20, 15));

    std::cout << "=== ENEMIES ===\n";

    for (const auto& e : enemies) {
        e->print();
        std::cout << "Damage: " << e->calculate_damage() << std::endl;
    }

    std::cout << "=== TOTAL DAMAGE ===\n";
    std::cout << waveTotalDamage(enemies) << std::endl;

    for (const auto e : enemies) {
        delete e;
    }

    return 0;
}