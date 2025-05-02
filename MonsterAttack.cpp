#include "Animation.h"
#include "Entity.h"
#include "Player.h"
#include "Monster.h"
#include "MonsterAttack.h"

#include <iostream>
#include <SFML/Graphics.hpp>

MonsterAttack::MonsterAttack(Monster &monster, unsigned int row, float speed, float width, float height, const float attackTime, float totalTime = 0.f, float attackPositionXLeft = 0.f, float attackPositionXRight = 0.f, float attackPositionY = 0.f, unsigned int damage = 0) : monster(&monster), ROW(row), attackSpeed(speed), attackTime(attackTime), totalTime(totalTime), attackPositionXLeft(attackPositionXLeft), attackPositionXRight(attackPositionXRight), attackPositionY(attackPositionY), damage(damage)
{
    attackBody.setSize(sf::Vector2f(width, height));
    attackBody.setOrigin(width / 2.f, height / 2.f); // Set the origin of the attack hitbox to the center of the hitbox
}

MonsterAttack::~MonsterAttack()
{
}

void MonsterAttack::Update(float deltaTime, Player &player, sf::RectangleShape &healthBar)
{
    monster->setRow(ROW);   // Set the row of the attack animation
    totalTime += deltaTime; // Update the attack time

    if (totalTime >= attackTime) // If the attack time is over
    {
        if (attackBody.getGlobalBounds().intersects(player.getBody().getGlobalBounds())) // If the attack hitbox intersects with the player hitbox
        // if(abs(attackBody.getPosition().x - player.getPosition().x) < 50.f && abs(attackBody.getPosition().y-player.getPosition().y)< 30.f ) //If the player is in the range
        {
            // std::cout << "Collision detected!" << std::endl;
            player.setHealth(player.getHealth() - this->damage, healthBar); // Set the player health to the new health
        }
        totalTime = 0;                  // Reset the attack time
        monster->setIsAttacking(false); // Set the monster to not attacking
    }

    // Fix the attack direction and create the attack hitbox
    if (player.getPosition().x - monster->getBody().getPosition().x >= 0)
    {
        monster->setFaceRight(true);
        attackBody.setPosition(monster->getBody().getPosition().x + attackPositionXRight, monster->getBody().getPosition().y + attackPositionY);
    }
    else
    {
        monster->setFaceRight(false);
        attackBody.setPosition(monster->getBody().getPosition().x - attackPositionXLeft, monster->getBody().getPosition().y + attackPositionY);
    }

    attackBody.setFillColor(sf::Color::Black);

    attackBody.setTextureRect(monster->getAnimation().getUVRect());
}

void MonsterAttack::Draw(sf::RenderWindow &window, Monster &monster)
{
    if (monster.getIsAttacking())
    {
        window.draw(this->attackBody); // Draw the attack hitbox
    }
}

float MonsterAttack::getAttackSpeed() const
{
    return this->attackSpeed;
}
const float MonsterAttack::getTotalTime() const
{
    return totalTime;
}
const unsigned int MonsterAttack::getDamage() const
{
    return damage;
}
const float MonsterAttack::getAttackTime() const
{
    return attackTime;
}

void MonsterAttack::setTotalTime(float totalTime)
{
    this->totalTime = totalTime;
}