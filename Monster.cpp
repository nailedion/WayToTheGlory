#include "Animation.h"
#include "Entity.h"
#include "Player.h"
#include "Monster.h"

#include <SFML/Graphics.hpp>

Monster::Monster(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float x, float y, float width, float height) :
    Entity(texture, imageCount, switchTime, speed, x, y, width, height)
{
}

Monster::~Monster()
{
}

void Monster::Update(float deltaTime, Player& player)
{
    sf::Vector2f movement(0.f, 0.f);

    if (body.getPosition().x < player.getBody().getPosition().x)
        movement.x += speed * deltaTime;
    else if (body.getPosition().x > player.getBody().getPosition().x)
        movement.x -= speed * deltaTime;

    if (body.getPosition().y < player.getBody().getPosition().y)
        movement.y += speed * deltaTime;
    else if (body.getPosition().y > player.getBody().getPosition().y)
        movement.y -= speed * deltaTime;

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

void Monster::Draw(sf::RenderWindow& window)
{
    window.draw(this->body);
}