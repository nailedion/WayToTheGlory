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
    const float getHealth() const { return health; }

    void setIsAttacking(bool isAttacking) { this->isAttacking = isAttacking; }
    void setHealth(float health, sf::RectangleShape& healthBar)
    {
        if(health < 0.f)
            health = 0.f;
        else
            this->health = health;
        healthBar.setSize(sf::Vector2f(200.f * (health / maxHealth), 20.f));
    }

    void Update(float, Player&, MonsterAttack&, float, float, float, float, sf::RectangleShape&);
    void Draw(sf::RenderWindow&, MonsterAttack&);
};