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
            this->health = 0.f;
        else
            this->health = health;
        healthBar.setSize(sf::Vector2f(200.f * (health / maxHealth), 20.f));
        if(this->health <= 0.f)
            healthBar.setSize(sf::Vector2f(0.f, 20.f)); ///Sometimes the health bar goes negative, so we set it to 0.f
    }

    void Update(float, Player&, MonsterAttack&, float, float, float, float, sf::RectangleShape&);
    void Draw(sf::RenderWindow&, MonsterAttack&);

    Entity* clone() const override {
        return new Monster(*this);
    }

    virtual bool getIsAlive() const override { return this->getHealth() > 0; }
    virtual void update(float deltaTime, Monster& dragon, sf::RectangleShape& healthBarDragon) override{
        // Monster-specific update logic can be added here if needed
    }
};