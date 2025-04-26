#pragma once

#include "Animation.h"
#include "Entity.h"
// #include "Monster.h"

#include <SFML/Graphics.hpp>

class Monster; // Forward declaration of Monster class

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
        Attack(Entity&, const unsigned int, float, unsigned int, float, float);
        ~Attack();

        bool getIsAttacking() const { return this->isAttacking; }
        float getAttackSpeed() const { return this->attackSpeed; }

        bool Update(float deltaTime, Monster&, sf::RectangleShape&);
        void Draw(sf::RenderWindow& window);
};