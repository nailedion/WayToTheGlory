#pragma once

#include "Animation.h"
#include "Entity.h"
#include "Player.h"
#include "Attack.h"
#include "MonsterAttack.h"

#include <SFML/Graphics.hpp>

class Monster: public Entity
{
    private:
        bool isAttacking;
    public:
    Monster(sf::Texture*, sf::Vector2u, float, float, float, float, float, float, unsigned int, unsigned int, bool);
    ~Monster();

    const int getRow() const { return row; }
    const bool getIsAttacking() const { return isAttacking; }
    const sf::RectangleShape& getBody() const { return body; }
    const Animation& getAnimation() const { return animation; }

    void setIsAttacking(bool isAttacking) { this->isAttacking = isAttacking; }

    void Update(float, Player&, MonsterAttack&, float, float, float, float);
    void Draw(sf::RenderWindow&, MonsterAttack&);
};