#pragma once

#include "Animation.h"
#include "Entity.h"
#include "Attack.h"

#include <SFML/Graphics.hpp>

class Player : public Entity
{
    Player(sf::Texture *, sf::Vector2u, float, float, float, float, float, float, unsigned int, unsigned int);

public:
    Player(Entity &);
    ~Player();

    static Player& getPlayer(sf::Texture *, sf::Vector2u, float, float, float, float, float, float, unsigned int, unsigned int);

    sf::Vector2f getPosition() const;

    void setHealth(float, sf::RectangleShape &);

    void Update(float, Attack &);
    void Draw(sf::RenderWindow &);
    bool isMoving() const;

    Entity *clone() const override
    {
        return new Player(*this);
    }

    virtual bool getIsAlive() const override;
    virtual void update(float, Monster &, sf::RectangleShape &) override;
};