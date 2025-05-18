#pragma once

#include "Entity.h"
#include "Monster.h"

#include <SFML/Graphics.hpp>
#include <vector>

template <typename T>
class GameManager
{
    std::vector<T *> meteorites;
    
    GameManager() = default;

public:
    void operator=(GameManager &);
    friend void swap(GameManager &first, GameManager &);

    GameManager(const GameManager &);
    ~GameManager();

    static GameManager& getGameManager();

    void addMeteorite(T *);

    void removeMeteorite(T *);

    void updateMeteorites(float, Monster &, sf::RectangleShape &);
};

#include "GameManager.tpp"