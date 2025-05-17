#pragma once

#include "Animation.h"

#include <SFML/Graphics.hpp>

class Monster; // Forward declaration of Monster class

class Entity
{
protected:
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
    bool faceRight;
    unsigned int health;
    unsigned int maxHealth;

public:
    Entity(sf::Texture *, sf::Vector2u, float, float, float, float, float, float, unsigned int, unsigned int);
    Entity(const Entity &);
    virtual Entity *clone() const = 0;
    virtual ~Entity();

    bool getFaceRight() const;
    virtual const sf::RectangleShape &getBody() const;
    const Animation &getAnimation() const;
    const unsigned int getHealth() const;
    const unsigned int getMaxHealth() const;

    void setRow(const unsigned int);
    void setFaceRight(const bool);
    void setPosition(float, float);

    Entity &operator=(Entity &);

    virtual bool getIsAlive() const = 0;
    virtual void update(float, Monster &, sf::RectangleShape &) = 0;

    friend void swap(Entity &, Entity &);
};