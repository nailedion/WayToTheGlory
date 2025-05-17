#include "Entity.h"
#include "Monster.h"

#include <SFML/Graphics.hpp>
#include <vector>

class GameManager
{
    std::vector<Entity *> meteorites;
    
    GameManager() = default;

public:
    void operator=(GameManager &);
    friend void swap(GameManager &first, GameManager &);

    GameManager(const GameManager &);
    ~GameManager();

    static GameManager& getGameManager();

    void addMeteorite(Entity *);

    void removeMeteorite(Entity *);

    void updateMeteorites(float, Monster &, sf::RectangleShape &);
};