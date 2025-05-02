#include "Meteorit.h"
#include "Monster.h"     // Full definition needed here
#include "GameManager.h" // Include full definition of GameManager class
#include "ExceptionTypes.h"

#include <SFML/Graphics.hpp>

Meteorit::Meteorit(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed, float x, float y, float width, float height, unsigned int health, unsigned int maxHealth, float healInterval = 10.f, float healTimer = 0.f, float spownTime = 0.f, float spownTimer = 0.f)
    : Entity(texture, imageCount, switchTime, speed, x, y, width, height, health, maxHealth), healInterval(healInterval), healTimer(healTimer), spownTime(spownTime), spownTimer(spownTimer)
{
    body.setPosition(x, y);
    body.setOrigin(width / 2.f, height / 2.f);
}

bool Meteorit::getIsAlive() const
{
    return this->getHealth() > 0;
}

void Meteorit::takeDamage(float damage)
{
    health -= damage;
    if (health <= 0)
    {
        health = 0;
    }
}

void Meteorit::update(float deltaTime, Monster &dragon, sf::RectangleShape &healthBarDragon)
{
    if (!this->getIsAlive())
        return;

    healTimer += deltaTime;
    if (healTimer >= healInterval)
    {
        healTimer = 0.f;
        if (dragon.getHealth() < dragon.getMaxHealth())
            dragon.setHealth(dragon.getHealth() + 5, healthBarDragon);
    }
}

void Meteorit::draw(sf::RenderWindow &window)
{
    if (this->getIsAlive())
    {
        window.draw(body);
    }
}

void Meteorit::spown(float deltaTime, std::vector<Meteorit *> &meteorites, GameManager &gameManager)
{
    spownTimer += deltaTime;
    if (spownTimer >= spownTime)
    {
        spownTimer = 0.f;

        for (int i = 0; i < 3; i++)
        {
            Meteorit *meteorit = static_cast<Meteorit *>(this->clone());

            unsigned int x = 15 + rand() % (1265 - 15 + 1), y = 25 + rand() % (775 - 25 + 1);
            body.setPosition(x, y);

            meteorites.push_back(meteorit);
            gameManager.addMeteorite(meteorit); // Add the new meteorite to the game manager
        }
    }
}

Entity *Meteorit::clone() const
{
    return new Meteorit(*this);
}

void Meteorit::killIfCollides(Monster &dragon)
{
    if (std::abs(this->getBody().getPosition().x - dragon.getBody().getPosition().x) < 50.f && std::abs(this->getBody().getPosition().y - dragon.getBody().getPosition().y) < 25.f)
    {
        this->health = 0; // Set the metheorite's health to 0 if it collides with the meteorite
    }
}
