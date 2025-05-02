#include "Entity.h"
#include "Animation.h"
#include "ExceptionTypes.h"

#include <SFML/Graphics.hpp>

Entity::Entity(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float xPosition, float yPosition, float width, float height, unsigned int health, unsigned int maxHealth) :
    animation(texture, imageCount, switchTime), health(health), maxHealth(maxHealth)
{
    if (health > maxHealth) {
        throw InvalidEntityException("Entity health exceeds maxHealth");
    }
    this->speed = speed;
    row = 0;
    faceRight = true;

    body.setSize(sf::Vector2f(width, height));
    body.setPosition(xPosition, yPosition);
    body.setTexture(texture);
    body.setOrigin(body.getSize().x / 2, body.getSize().y / 2);
}

bool Entity::getFaceRight() const { return this->faceRight; }

const sf::RectangleShape& Entity::getBody() const { return this->body; }

const Animation& Entity::getAnimation() const { return this->animation; }

void Entity::setRow(const unsigned int ROW) { row = ROW; }

Entity::Entity(const Entity& entity) :
    animation(entity.animation)
{
    this->body = entity.body;
    this->row = entity.row;
    this->speed = entity.speed;
    this->faceRight = entity.faceRight;
    this->health = entity.health;
    this->maxHealth = entity.maxHealth;
}

Entity::~Entity()
{
}

Entity& Entity::operator=(Entity& entity)
{
    if (this != &entity) {
        swap(*this, entity);
    }
    return *this;
}