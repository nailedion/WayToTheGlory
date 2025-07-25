#include "Meteorite.h"
#include "Monster.h"     // Full definition needed here
#include "GameManager.h" // Include full definition of GameManager class
#include "ExceptionTypes.h"

#include <SFML/Graphics.hpp>

Meteorite::Meteorite(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed, float x, float y, float width, float height, unsigned int health, unsigned int maxHealth, float healInterval = 10.f, float healTimer = 0.f, float spownTime = 0.f, float spownTimer = 0.f)
    : Entity(texture, imageCount, switchTime, speed, x, y, width, height, health, maxHealth), healInterval(healInterval), healTimer(healTimer), spownTime(spownTime), spownTimer(spownTimer)
{
    body.setPosition(x, y);
    body.setOrigin(width / 2.f, height / 2.f);
}

bool Meteorite::getIsAlive() const
{
    return this->getHealth() > 0;
}

void Meteorite::takeDamage(float damage)
{
    health -= damage;
    if (health <= 0)
    {
        health = 0;
    }
}

void Meteorite::update(float deltaTime, Monster &dragon, sf::RectangleShape &healthBarDragon)
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

void Meteorite::draw(sf::RenderWindow &window)
{
    if (this->getIsAlive())
    {
        window.draw(body);
    }
}

void Meteorite::spown(float deltaTime, GameManager<Meteorite> &gameManager)
{
    spownTimer += deltaTime;
    if (spownTimer >= spownTime)
    {
        spownTimer = 0.f;

        for (int i = 0; i < 3; i++)
        {
            Meteorite *meteorite = static_cast<Meteorite *>(this->clone());

            unsigned int x = 15 + rand() % (1265 - 15 + 1), y = 25 + rand() % (775 - 25 + 1);
            meteorite->setPosition(x, y);

            gameManager.addMeteorite(meteorite);
        }
    }
}

Entity *Meteorite::clone() const
{
    return new Meteorite(*this);
}

void Meteorite::killIfCollides(Monster &dragon)
{
    if (std::abs(this->getBody().getPosition().x - dragon.getBody().getPosition().x) < 50.f && std::abs(this->getBody().getPosition().y - dragon.getBody().getPosition().y) < 25.f)
    {
        this->health = 0; // Set the meteorite's health to 0 if it collides with the meteorite
    }
}
