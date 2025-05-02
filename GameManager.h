#include "Entity.h"
#include "Monster.h"

#include <SFML/Graphics.hpp>
#include <vector>

class GameManager
{
protected:
    std::vector<Entity *> meteorites;

public:
    void operator=(GameManager &);
    friend void swap(GameManager &first, GameManager &);

    GameManager() = default;
    GameManager(const GameManager &);
    ~GameManager();

    void addMeteorite(Entity *);

    void removeMeteorite(Entity *);

    void updateMeteorites(float, Monster &, sf::RectangleShape &);
};