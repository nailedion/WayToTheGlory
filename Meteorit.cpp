#include "Meteorit.h"
#include "Monster.h" // Full definition needed here
#include "GameManager.h" // Include full definition of GameManager class

void Meteorit::update(float deltaTime, Monster& dragon, sf::RectangleShape& healthBarDragon) {
    if (!this->getIsAlive()) return;

    healTimer += deltaTime;
    if (healTimer >= healInterval) {
        healTimer = 0.f;
        if (dragon.getHealth() < dragon.getMaxHealth())
            dragon.setHealth(dragon.getHealth() + 10, healthBarDragon);
    }
}

void Meteorit::spown(float deltaTime, std::vector<Meteorit*>& meteorites, GameManager& gameManager) {
    spownTimer += deltaTime;
    if (spownTimer >= spownTime) {
        spownTimer = 0.f;
    
        for(int i =0; i<3 ; i++)
        {
            Meteorit* meteorit = static_cast<Meteorit*>(this->clone());

            unsigned int x = 15 + rand() % (1265 - 15 + 1), y = 25 + rand() % (775 - 25 + 1);
            body.setPosition(x, y);

            meteorites.push_back(meteorit);
            gameManager.addMeteorite(meteorit); // Add the new meteorite to the game manager
        }
    }
}

void Meteorit::killIfCollides(Monster& dragon) {
    if (std::abs(this->getBody().getPosition().x - dragon.getBody().getPosition().x)< 50.f && std::abs(this->getBody().getPosition().y - dragon.getBody().getPosition().y) < 25.f) {
        this->health=0; // Set the monster's health to 0 if it collides with the meteorite
    }
}   
