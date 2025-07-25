#pragma once

#include "Entity.h"
#include "Monster.h"
#include "Meteorite.h"

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

    void updateMeteorites(float, Monster &, sf::RectangleShape &);

    std::vector<T*>& getMeteorites() { return meteorites; }

    template <typename ptrVector, typename lambda>
    friend void removeIfPtr(ptrVector&, lambda);
};

// #include "GameManager.cpp"  // Not recommended to include .cpp files in header files bc it will be compiled multiple times. But I'll let it here for demonstration purposes. If you want to use it, just uncomment this line and the task line for GameManager.cpp.
//Update: doesn't work anymore, the game has been updated and it was considered a bad practice anyway.
#include "GameManager.tpp"