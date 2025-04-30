#include "Animation.h"
#include "Entity.h"
#include "Monster.h"
#include "Attack.h"
#include "Meteorit.h"

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

// class Monster; // Forward declaration of Monster class

Attack::Attack(Entity& entity, unsigned int ROW, float speed, unsigned int damage=0, float attackTime=0.f, float totalTime=0.f) :
    entity(&entity), ROW(ROW), attackSpeed(speed), isAttacking(false), damage(damage), attackTime(attackTime), totalTime(totalTime)
{
    attackBody.setSize(sf::Vector2f(50.f, 25.f));
}

Attack::~Attack()
{
}

bool Attack::Update(float deltaTime, Monster& dragon, sf::RectangleShape& healthBarDragon, std::vector<Meteorit*>& meteorites)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isAttacking)
    {
        attackTime += deltaTime; // Update the attack time

        this->isAttacking = true;
        entity->setRow(ROW);

        // attackBody.setFillColor(sf::Color::Red);
        
        if(entity->getFaceRight())
            attackBody.setPosition(entity->getBody().getPosition().x , entity->getBody().getPosition().y - 15.f);
        else
            attackBody.setPosition(entity->getBody().getPosition().x - 50.f, entity->getBody().getPosition().y - 15.f);
        attackBody.setTextureRect(entity->getAnimation().getUVRect());


        if(attackTime >= totalTime){
            // if(dragon.getBody().getGlobalBounds().intersects(attackBody.getGlobalBounds()))
            if(abs(dragon.getBody().getPosition().x - attackBody.getPosition().x) < 110.f && abs(dragon.getBody().getPosition().y - attackBody.getPosition().y) < 25.f)
            {
                // std::cout << "Collision detected!" << std::endl;
                dragon.setHealth(dragon.getHealth() - damage, healthBarDragon); // Reduce the monster's health by the attack damage
                // std::cout << "Monster health: " << dragon.getHealth() << std::endl;
            }

            for (auto& meteorit : meteorites)
                    if (attackBody.getGlobalBounds().intersects(meteorit->getBody().getGlobalBounds()))
                        meteorit->takeDamage(damage);

            attackTime = 0; // Reset the attack time
        }
    }
    else
        isAttacking = false;

    return isAttacking;
}

void Attack::Draw(sf::RenderWindow& window)
{
    if (isAttacking)
    {
        window.draw(this->attackBody);
    }
}