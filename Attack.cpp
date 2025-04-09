#include "Entity.h"
#include "Attack.h"

#include <SFML/Graphics.hpp>

Attack::Attack(Entity& entity, unsigned int ROW, float speed):
    entity(&entity), ROW(ROW), attackSpeed(speed), isAttacking(false)
{
    attackBody.setSize(sf::Vector2f(50.f, 50.f));
}

Attack::~Attack()
{
}

bool Attack::Update(float deltaTime)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isAttacking)
    {
        this->isAttacking = true;
        entity->setRow(ROW);
        attackBody.setFillColor(sf::Color::Red);
        if(entity->getFaceRight())
            attackBody.setPosition(entity->getBody().getPosition().x , entity->getBody().getPosition().y - 15.f);
        else
            attackBody.setPosition(entity->getBody().getPosition().x - 50.f, entity->getBody().getPosition().y - 15.f);
        attackBody.setTextureRect(entity->getAnimation().getUVRect());
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