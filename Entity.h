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
        Entity(sf::Texture*, sf::Vector2u, float, float);
        Entity(const Entity&);
        ~Entity();
};