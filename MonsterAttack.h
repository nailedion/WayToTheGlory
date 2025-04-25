#pragma once

#include "Animation.h"
#include "Entity.h"
#include "Player.h"
// #include "Monster.h"

#include <SFML/Graphics.hpp>

class Monster; // Forward declaration of Monster class

class MonsterAttack{
    private:
        Monster* monster;
        sf::RectangleShape attackBody;
        const unsigned int ROW;
        float attackSpeed;
        const float attackTime;
        float totalTime;
        float attackPositionXLeft;
        float attackPositionXRight;
        float attackPositionY;

    public:
        MonsterAttack(Monster&, const unsigned int, float, float, float, const float, float, float, float, float);
        ~MonsterAttack();

        float getAttackSpeed() const;
        const float getTotalTime() const { return totalTime; }

        void Update(float, Player&);
        void Draw(sf::RenderWindow&, Monster&);
};