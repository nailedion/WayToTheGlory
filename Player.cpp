#include "Player.h"
#include "Animation.h"
#include "Entity.h"
#include "Attack.h"
#include "ExceptionTypes.h"

#include <SFML/Graphics.hpp>

Player::Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed, float xPosition, float yPosition, float width, float height, unsigned int health, unsigned int maxHealth) : Entity(texture, imageCount, switchTime, speed, xPosition, yPosition, width, height, health, maxHealth)
{
}

Player::Player(Entity &entity) : Entity(entity)
{
}

Player::~Player()
{
}

Player& Player::getPlayer(sf::Texture * texture, sf::Vector2u imageCount, float switchTime, float speed, float xPosition, float yPosition, float width, float height, unsigned int health, unsigned int maxHealth)
{
    static Player instance(texture, imageCount, switchTime, speed, xPosition, yPosition, width, height, health, maxHealth);
    return instance;
}

sf::Vector2f Player::getPosition() const
{
    return body.getPosition();
}

void Player::setHealth(float health, sf::RectangleShape &healthBar)
{
    if (health < 0.f)
        this->health = 0.f;
    else
        this->health = health;
    healthBar.setSize(sf::Vector2f(200.f * (float(this->health) / maxHealth), 20.f));
}

void Player::Update(float deltaTime, Attack &playerAttack)
{
    if (health <= 0) // If the player is dead
    {
        row = 3;                                                             // Set the player to the dead animation
        if (animation.getCurrentImage().x < animation.getImageCount().x - 1) // If the monster is not dead(last image of being dead) update the animation
            animation.Update(row, deltaTime, faceRight);
        body.setTextureRect(animation.getUVRect());
        return;
    }

    if (playerAttack.getIsAttacking())
    {
        animation.Update(row, deltaTime * playerAttack.getAttackSpeed() / speed, faceRight);
        return;
    }

    if (body.getPosition().x < 0 || body.getPosition().x > 1280 ||
        body.getPosition().y < 0 || body.getPosition().y > 800)
    {
        throw StateException("Player has moved out of bounds!");
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
        if (movement.x == 0.f && movement.y == 0.f)
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

void Player::Draw(sf::RenderWindow &window)
{
    window.draw(body);
}

bool Player::getIsAlive() const
{
    return this->getHealth() > 0;
}
void Player::update(float deltaTime, Monster &dragon, sf::RectangleShape &healthBarDragon)
{
    // Player-specific update logic can be added here if needed
}