#include "GameManager.h"
#include "Meteorite.h"
#include "Monster.h"

template <typename T>
void GameManager<T>::operator=(GameManager<T> &other) // usless
{
    if (this != &other)
    {
        swap(*this, other);
    }
}

template <typename T>
GameManager<T> &GameManager<T>::getGameManager()
{
    static GameManager<T> instance;
    return instance;
}

template <typename T>
void swap(GameManager<T> &first, GameManager<T> &second)
{
    std::swap(first.meteorites, second.meteorites);
}

template <typename T>
GameManager<T>::GameManager(const GameManager<T> &other)
{
    for (const auto &meteorite : other.meteorites)
    {
        meteorites.push_back(meteorite->clone()); // presupunem că clone() face deep copy
    }
}

template <typename T>
GameManager<T>::~GameManager()
{
    for (auto &meteorite : meteorites)
    {
        delete meteorite;
    }
}

template <typename T>
void GameManager<T>::addMeteorite(T *meteorite)
{
    meteorites.push_back(meteorite);
}

template <typename T>
void GameManager<T>::updateMeteorites(float deltaTime, Monster &dragon, sf::RectangleShape &healthBarDragon)
{
    for (auto &meteorite : meteorites)
    {
        if (meteorite->getIsAlive())
        {
            meteorite->update(deltaTime, dragon, healthBarDragon);
        }

        if (Meteorite* castedMeteorite = dynamic_cast<Meteorite*>(meteorite))
        {
            castedMeteorite->killIfCollides(dragon);
        }
    }
    
    removeIfPtr(meteorites, [](T* m) { return !m->getIsAlive(); });
}
