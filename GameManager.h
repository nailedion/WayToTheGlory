#include "Entity.h"
#include "Monster.h"

#include <SFML/Graphics.hpp>
#include <vector>

class GameManager
{
protected:
    std::vector<Entity *> meteorites;

public:
    void operator=(GameManager &other);
    friend void swap(GameManager &first, GameManager &second);

    GameManager() = default;
    GameManager(const GameManager &other);
    ~GameManager();

    void addMeteorite(Entity *meteorite);

    void removeMeteorite(Entity *meteorite);

    void updateMeteorites(float deltaTime, Monster &dragon, sf::RectangleShape &healthBarDragon);
};