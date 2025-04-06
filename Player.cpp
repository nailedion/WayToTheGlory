#include "Player.h"
#include "Animation.h"

#include <SFML/Graphics.hpp>

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed):
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    row = 0;
    faceRight = true;

    body.setSize(sf::Vector2f(100.f, 65.f));
    body.setPosition(640.f, 400.f);
    body.setTexture(texture);
    body.setOrigin(body.getSize().x / 2, body.getSize().y / 2);
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
    sf::Vector2f movement(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && body.getPosition().y - 37.5 > 0.f)
        movement.y -= speed * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && body.getPosition().x - 50 > 0.f)
        movement.x -= speed * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && body.getPosition().y + 37.5 < 800.f)
        movement.y += speed * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && body.getPosition().x + 50 < 1280.f)
        movement.x += speed * deltaTime;

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

    animation.Update(row, deltaTime, faceRight);
    body.setTextureRect(animation.getUVRect());
    body.move(movement);
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}