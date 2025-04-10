#pragma once

#include "Animation.h"
#include "Entity.h"
#include "Attack.h"

#include <SFML/Graphics.hpp>

class Player: public Entity
{

    public:
        Player(sf::Texture*, sf::Vector2u, float, float, float, float, float, float);
        Player(Entity&);
        ~Player();

        void Update(float deltaTime, Attack&);
        void Draw(sf::RenderWindow&);
        bool isMoving() const;
};