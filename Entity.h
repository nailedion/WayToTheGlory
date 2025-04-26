#pragma once

#include "Animation.h"

#include <SFML/Graphics.hpp>

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
        Entity(sf::Texture*, sf::Vector2u, float, float, float, float, float, float, unsigned int, unsigned int);
        Entity(const Entity&);
        ~Entity();

        bool getFaceRight() const;
        const sf::RectangleShape& getBody() const;
        const Animation& getAnimation() const;
        const unsigned int getHealth() const { return health; }
        const unsigned int getMaxHealth() const { return maxHealth; }

        void setRow(const unsigned int ROW);
        void setFaceRight(const bool faceRight) { this->faceRight = faceRight; }

        Entity& operator=(const Entity&);
};