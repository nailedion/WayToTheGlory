#include "GameManager.h"
#include "Meteorite.h"
#include "Monster.h"

void GameManager::operator=(GameManager &other)
{
    if (this != &other)
    {
        swap(meteorites, other.meteorites);
    }
}

GameManager& GameManager::getGameManager()
{
    static GameManager instance;
    return instance;
}

void swap(GameManager &first, GameManager &second)
{
    std::swap(first.meteorites, second.meteorites);
}

GameManager::GameManager(const GameManager &other)
{
    for (const auto &meteorite : other.meteorites)
    {
        meteorites.push_back(meteorite->clone()); // Assuming clone() creates a deep copy
    }
}

GameManager::~GameManager()
{
    for (auto &meteorite : meteorites)
    {
        delete meteorite;
    }
}

void GameManager::addMeteorite(Entity *meteorite)
{
    meteorites.push_back(meteorite);
}

void GameManager::removeMeteorite(Entity *meteorite)
{
    auto it = std::remove(meteorites.begin(), meteorites.end(), meteorite);
    if (it != meteorites.end())
    {
        delete *it;
        meteorites.erase(it, meteorites.end());
    }
}

void GameManager::updateMeteorites(float deltaTime, Monster &dragon, sf::RectangleShape &healthBarDragon)
{
    for (auto &meteorite : meteorites)
    {
        if (meteorite->getIsAlive())
        {
            meteorite->update(deltaTime, dragon, healthBarDragon);
        }

        if (Meteorite *castedMeteorite = dynamic_cast<Meteorite *>(meteorite))
        {
            castedMeteorite->killIfCollides(dragon);
        }
    }
}