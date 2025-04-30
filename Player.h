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

        void setHealth(float health, sf::RectangleShape& healthBar)
        {
            if(health < 0.f)
                this->health = 0.f;
            else
                this->health = health;
            healthBar.setSize(sf::Vector2f(200.f * (float(this->health) / maxHealth), 20.f));
        }

        void Update(float deltaTime, Attack&);
        void Draw(sf::RenderWindow&);
        bool isMoving() const;

        Entity* clone() const override {
            return new Player(*this);
        }    
};