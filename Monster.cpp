#include "Animation.h"
#include "Entity.h"
#include "Player.h"
#include "Monster.h"
#include "MonsterAttack.h"

#include <iostream>
#include <SFML/Graphics.hpp>

Monster::Monster(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float x, float y, float width, float height, unsigned int health, unsigned int maxHealth, bool isAttacking = false) :
    Entity(texture, imageCount, switchTime, speed, x, y, width, height, health, maxHealth), isAttacking(isAttacking)
{
}

Monster::~Monster()
{
}

void Monster::Update(float deltaTime, Player& player, MonsterAttack& monsterAttack, float attackDistanceXLeft, float attackDistanceXRight, float attackDistanceYUp, float attackDistanceYDown, sf::RectangleShape& healthBar)
{
    if (health <= 0.f) //If the monster is dead
    {
        row = 3; //Set the monster to the dead animation
        if(animation.getCurrentImage().x < animation.getImageCount().x - 1) //If the monster is not dead(last image of being dead) update the animation
            animation.Update(row, deltaTime, faceRight);
        body.setTextureRect(animation.getUVRect());
        return;
    }

    if(isAttacking)
    {
        monsterAttack.Update(deltaTime, player, healthBar); //Update the attack animation
        animation.Update(row, deltaTime, faceRight);
        body.setTextureRect(animation.getUVRect()); 
        return;
    }

    sf::Vector2f movement(0.f, 0.f);

    //If the monster is on the right side of the player
    if (body.getPosition().x > player.getBody().getPosition().x + attackDistanceXRight)
        movement.x -= speed * deltaTime;
    else
        if (body.getPosition().x < player.getBody().getPosition().x - attackDistanceXLeft)
            movement.x += speed * deltaTime;

    if (body.getPosition().y < player.getBody().getPosition().y - attackDistanceYUp) ///Move towards the player on the Y axis
        movement.y += speed * deltaTime;
    else if (body.getPosition().y > player.getBody().getPosition().y + attackDistanceYDown)
        movement.y -= speed * deltaTime;

    if(movement.x == 0.f && movement.y == 0.f && 
       std::abs(body.getPosition().x - player.getBody().getPosition().x) < 100.f && 
       std::abs(body.getPosition().y - player.getBody().getPosition().y) < 100.f)
    {
        isAttacking = true;
    }
    else
    {
        row = 1;
        if (movement.x > 0.f)
            faceRight = true;
        else if (movement.x < 0.f)
            faceRight = false;
    }

    animation.Update(row, deltaTime, faceRight);
    body.setTextureRect(animation.getUVRect());
    body.move(movement);
}

void Monster::Draw(sf::RenderWindow& window, MonsterAttack& monsterAttack)
{
    window.draw(this->body);
    // monsterAttack.Draw(window, *this); //Draw the attack hitbox just for testing purposes
}