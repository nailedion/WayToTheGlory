#pragma once

#include "Animation.h"
#include "Entity.h"
#include "Player.h"
// #include "Monster.h"

#include <SFML/Graphics.hpp>

class Monster; // Forward declaration of Monster class

class MonsterAttack
{
private:
    Monster *monster;
    sf::RectangleShape attackBody;
    const unsigned int ROW;
    float attackSpeed;
    const float attackTime;
    float totalTime;
    float attackPositionXLeft;
    float attackPositionXRight;
    float attackPositionY;
    unsigned int damage;

public:
    MonsterAttack(Monster &, const unsigned int, float, float, float, const float, float, float, float, float, unsigned int);
    ~MonsterAttack();

    float getAttackSpeed() const;
    const float getTotalTime() const;
    const unsigned int getDamage() const;
    const float getAttackTime() const;

    void setTotalTime(float);

    void Update(float, Player &, sf::RectangleShape &);
    void Draw(sf::RenderWindow &, Monster &);
};