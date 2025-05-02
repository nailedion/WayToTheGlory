#pragma once

#include "Animation.h"
#include "Entity.h"
#include "Attack.h"

#include <SFML/Graphics.hpp>

class Player : public Entity
{

public:
    Player(sf::Texture *, sf::Vector2u, float, float, float, float, float, float, unsigned int, unsigned int);
    Player(Entity &);
    ~Player();

    sf::Vector2f getPosition() const;

    void setHealth(float health, sf::RectangleShape &healthBar);

    void Update(float deltaTime, Attack &);
    void Draw(sf::RenderWindow &);
    bool isMoving() const;

    Entity *clone() const override
    {
        return new Player(*this);
    }

    virtual bool getIsAlive() const override;
    virtual void update(float deltaTime, Monster &dragon, sf::RectangleShape &healthBarDragon) override;
};