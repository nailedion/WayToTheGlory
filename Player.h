#pragma once

#include "Animation.h"
#include "Entity.h"
#include "Attack.h"

#include <SFML/Graphics.hpp>

class Player: public Entity
{

    public:
        Player(sf::Texture*, sf::Vector2u, float, float, float, float, float, float, unsigned int, unsigned int);
        Player(Entity&);
        ~Player();

        sf::Vector2f getPosition() const;
        void Update(float deltaTime, Attack&);
        void Draw(sf::RenderWindow&);
        bool isMoving() const;
};