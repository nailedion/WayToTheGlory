#pragma once

#include "Entity.h"

#include <SFML/Graphics.hpp>

class Attack
{
    private:
        Entity *entity;
        sf::RectangleShape attackBody;
        const unsigned int ROW;
        float attackSpeed;
        bool isAttacking;

    public:
        Attack(Entity&, const unsigned int, float speed);
        ~Attack();

        bool getIsAttacking() const { return this->isAttacking; }
        float getAttackSpeed() const { return this->attackSpeed; }

        bool Update(float deltaTime);
        void Draw(sf::RenderWindow& window);
};