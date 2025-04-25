#include "Animation.h"
#include "Entity.h"
#include "Player.h"
#include "Monster.h"
#include "MonsterAttack.h"

#include <SFML/Graphics.hpp>

MonsterAttack::MonsterAttack(Monster& monster, unsigned int row, float speed, float width, float height, const float attackTime, float totalTime=0.f, float attackPositionXLeft=0.f, float attackPositionXRight=0.f, float attackPositionY=0.f) :
    monster(&monster), ROW(row), attackSpeed(speed), attackTime(attackTime), totalTime(totalTime), attackPositionXLeft(attackPositionXLeft), attackPositionXRight(attackPositionXRight), attackPositionY(attackPositionY)
{
    attackBody.setSize(sf::Vector2f(width, height));
}
MonsterAttack::~MonsterAttack()
{
}

void MonsterAttack::Update(float deltaTime, Player& player)
{
    monster->setRow(ROW); //Set the row of the attack animation
    totalTime += deltaTime; //Update the attack time

    if(totalTime >= attackTime) //If the attack time is over
    {
        totalTime = 0; //Reset the attack time
        monster->setIsAttacking(false); //Set the monster to not attacking
    }

    //Fix the attack direction and create the attack hitbox
    if(player.getPosition().x - monster->getBody().getPosition().x >= 0){
        monster->setFaceRight(true);
        attackBody.setPosition(monster->getBody().getPosition().x + attackPositionXRight, monster->getBody().getPosition().y + attackPositionY);
    }
    else{
        monster->setFaceRight(false);
        attackBody.setPosition(monster->getBody().getPosition().x - attackPositionXLeft, monster->getBody().getPosition().y + attackPositionY);
    }

    attackBody.setFillColor(sf::Color::Black);

    attackBody.setTextureRect(monster->getAnimation().getUVRect());
}

void MonsterAttack::Draw(sf::RenderWindow& window, Monster& monster) {
    if(monster.getIsAttacking())
    {
        window.draw(this->attackBody); //Draw the attack hitbox
    }
}

float MonsterAttack::getAttackSpeed() const { return this->attackSpeed; }