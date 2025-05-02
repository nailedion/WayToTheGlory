#pragma once

#include "Animation.h"
#include "Entity.h"
#include "Player.h"
#include "Attack.h"
#include "MonsterAttack.h"

#include <SFML/Graphics.hpp>

class Monster : public Entity
{
private:
    bool isAttacking;

public:
    Monster(sf::Texture *, sf::Vector2u, float, float, float, float, float, float, unsigned int, unsigned int, bool);
    ~Monster();

    const int getRow() const;
    const bool getIsAttacking() const;
    const sf::RectangleShape &getBody() const;
    const Animation &getAnimation() const;
    const float getHealth() const;

    void setIsAttacking(bool isAttacking);
    void setHealth(float health, sf::RectangleShape &healthBar);

    void Update(float, Player &, MonsterAttack &, float, float, float, float, sf::RectangleShape &);
    void Draw(sf::RenderWindow &, MonsterAttack &);

    Entity *clone() const override;

    virtual bool getIsAlive() const override;
    virtual void update(float deltaTime, Monster &dragon, sf::RectangleShape &healthBarDragon) override;
};