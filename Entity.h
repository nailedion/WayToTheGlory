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

    public:
        Entity(sf::Texture*, sf::Vector2u, float, float, float, float, float, float);
        Entity(const Entity&);
        ~Entity();

        bool getFaceRight() const;
        const sf::RectangleShape& getBody() const;
        const Animation& getAnimation() const;

        void setRow(const unsigned int ROW);

        Entity& operator=(const Entity&);
};