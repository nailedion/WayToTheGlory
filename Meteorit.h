#pragma once

#include "Entity.h"
// #include "GameManager.h"
// #include "Monster.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

class Monster;
class GameManager; // Forward declaration of GameManager class

class Meteorit : public Entity {
private:
    float healInterval;
    float healTimer;
    float spownTime;
    float spownTimer;

public:
    Meteorit(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float x, float y, float width, float height, unsigned int health, unsigned int maxHealth, float healInterval = 10.f, float healTimer = 0.f, float spownTime = 0.f, float spownTimer = 0.f)
        : Entity(texture, imageCount, switchTime, speed, x, y, width, height, health, maxHealth), healInterval(healInterval), healTimer(healTimer), spownTime(spownTime), spownTimer(spownTimer) {
            body.setPosition(x, y);
            body.setOrigin(width / 2.f, height / 2.f);
        }

    virtual bool getIsAlive() const { return this->getHealth() > 0; }

    void takeDamage(float damage) {
        health -= damage;
        if (health <= 0) {
            health = 0;
        }
    }

    virtual void update(float deltaTime, Monster& dragon, sf::RectangleShape& healthBarDragon);

    void draw(sf::RenderWindow& window)
    {
        if(this->getIsAlive())
        {
            window.draw(body);
        }
    }

    void spown(float deltaTime, std::vector<Meteorit*>& meteorites, GameManager& gameManager);

    virtual Entity* clone() const override {
        return new Meteorit(*this);
    }

    void killIfCollides(Monster& dragon);
};