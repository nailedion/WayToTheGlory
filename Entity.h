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
        Entity(sf::Texture*, sf::Vector2u, float, float, float, float, float, float, unsigned int, unsigned int);
        Entity(const Entity&);
        virtual Entity* clone() const = 0;
        ~Entity();

        bool getFaceRight() const;
        virtual const sf::RectangleShape& getBody() const;
        const Animation& getAnimation() const;
        const unsigned int getHealth() const { return health; }
        const unsigned int getMaxHealth() const { return maxHealth; }

        void setRow(const unsigned int ROW);
        void setFaceRight(const bool faceRight) { this->faceRight = faceRight; }
        void setPosition(float x, float y) { body.setPosition(x, y); }

        Entity& operator=(Entity&);

        virtual bool getIsAlive() const = 0;
        virtual void update(float deltaTime, Monster& dragon, sf::RectangleShape& healthBarDragon) = 0;

        friend void swap(Entity& first, Entity& second) {
            std::swap(first.body, second.body);
            std::swap(first.animation, second.animation);
            std::swap(first.row, second.row);
            std::swap(first.speed, second.speed);
            std::swap(first.faceRight, second.faceRight);
            std::swap(first.health, second.health);
            std::swap(first.maxHealth, second.maxHealth);
        }
};