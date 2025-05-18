#pragma once

#include "Entity.h"
// #include "GameManager.h"
// #include "Monster.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

class Monster;
template <typename T>
class GameManager; // Forward declaration of GameManager class

class Meteorite : public Entity
{
private:
    float healInterval;
    float healTimer;
    float spownTime;
    float spownTimer;

public:
    Meteorite(sf::Texture*, sf::Vector2u, float, float, float, float, float, float, unsigned int, unsigned int, float, float, float, float);

    virtual bool getIsAlive() const;

    void takeDamage(float);

    virtual void update(float, Monster &, sf::RectangleShape &);

    void draw(sf::RenderWindow &);

    void spown(float, std::vector<Meteorite *> &, GameManager<Meteorite> &);

    virtual Entity *clone() const override;

    void killIfCollides(Monster &);
};