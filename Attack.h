#pragma once

#include "Animation.h"
#include "Entity.h"
#include "Meteorite.h"
// #include "Monster.h"

#include <vector>
#include <SFML/Graphics.hpp>

class Monster;

class Attack
{
private:
    Entity *entity;
    sf::RectangleShape attackBody;
    const unsigned int ROW;
    float attackSpeed;
    bool isAttacking;
    unsigned int damage;
    float attackTime;
    const float totalTime;

public:
    Attack(Entity &, const unsigned int, float, unsigned int, float, float);
    ~Attack();

    bool getIsAttacking() const;
    float getAttackSpeed() const;

    bool Update(float, Monster &, sf::RectangleShape &, std::vector<Meteorite *> &);
    void Draw(sf::RenderWindow &);
};