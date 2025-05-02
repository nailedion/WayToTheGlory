#pragma once

#include "Entity.h"
// #include "GameManager.h"
// #include "Monster.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

class Monster;
class GameManager; // Forward declaration of GameManager class

class Meteorit : public Entity
{
private:
    float healInterval;
    float healTimer;
    float spownTime;
    float spownTimer;

public:
    Meteorit(sf::Texture*, sf::Vector2u, float, float, float, float, float, float, unsigned int, unsigned int, float, float, float, float);

    virtual bool getIsAlive() const;

    void takeDamage(float damage);

    virtual void update(float deltaTime, Monster &dragon, sf::RectangleShape &healthBarDragon);

    void draw(sf::RenderWindow &window);

    void spown(float deltaTime, std::vector<Meteorit *> &meteorites, GameManager &gameManager);

    virtual Entity *clone() const override;

    void killIfCollides(Monster &dragon);
};