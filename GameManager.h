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

    template <typename U>
    friend void swap(GameManager<U> &first, GameManager<U> &second);


    GameManager(const GameManager &);
    ~GameManager();

    static GameManager& getGameManager();

    void addMeteorite(T *);

    void removeMeteorite(T *);

    void updateMeteorites(float, Monster &, sf::RectangleShape &);
};

// #include "GameManager.cpp"  // Not recommended to include .cpp files in header files bc it will be compiled multiple times. But I'll let it here for demonstration purposes. If you want to use it, just uncomment this line and the task line for GameManager.cpp..
#include "GameManager.tpp"