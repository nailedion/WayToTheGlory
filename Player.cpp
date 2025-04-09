#include "Player.h"
#include "Animation.h"
#include "Entity.h"
#include "Attack.h"

#include <SFML/Graphics.hpp>

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
    Entity(texture, imageCount, switchTime, speed)
{
}

Player::Player(Entity& entity) : Entity(entity)
{
}

Player::~Player()
{
}

void Player::Update(float deltaTime, Attack& playerAttack)
{
    if(playerAttack.getIsAttacking()){
        animation.Update(row, deltaTime * playerAttack.getAttackSpeed()/speed, faceRight);
        return;
    }

    sf::Vector2f movement(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && body.getPosition().y - 37.5 > 0.f)
        movement.y -= speed * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && body.getPosition().x - 50 > 0.f)
        movement.x -= speed * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && body.getPosition().y + 37.5 < 800.f)
        movement.y += speed * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && body.getPosition().x + 50 < 1280.f)
        movement.x += speed * deltaTime;

    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        if(movement.x == 0.f && movement.y == 0.f)
        {
            row = 0;
        }
        else
        {
            row = 1;
            if (movement.x > 0.f)
                faceRight = true;
            else if (movement.x < 0.f)
                faceRight = false;
        }
    else if (movement.x > 0.f)
            faceRight = true;
        else if (movement.x < 0.f)
            faceRight = false;

    animation.Update(row, deltaTime, faceRight);
    body.setTextureRect(animation.getUVRect());
    body.move(movement);
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}