#include "Meteorit.h"
#include "Monster.h" // Full definition needed here

void Meteorit::update(float deltaTime, Monster& dragon, sf::RectangleShape& healthBarDragon) {
    if (!this->getIsAlive()) return;

    healTimer += deltaTime;
    if (healTimer >= healInterval) {
        healTimer = 0.f;
        if (dragon.getHealth() < dragon.getMaxHealth())
            dragon.setHealth(dragon.getHealth() + 10, healthBarDragon);
    }
}
