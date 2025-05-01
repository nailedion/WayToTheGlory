#include "Entity.h"
#include "Monster.h"

#include <SFML/Graphics.hpp>
#include <vector>

class GameManager {
protected:
    std::vector<Entity*> meteorites;

public:
    GameManager() = default;
    ~GameManager() {
        for (auto& meteorite : meteorites) {
            delete meteorite;
        }
    }

    void addMeteorite(Entity* meteorite) {
        meteorites.push_back(meteorite);
    }

    void removeMeteorite(Entity* meteorite) {
        auto it = std::remove(meteorites.begin(), meteorites.end(), meteorite);
        if (it != meteorites.end()) {
            delete *it; // Free the memory
            meteorites.erase(it, meteorites.end());
        }
    }

    void updateMeteorites(float deltaTime, Monster& dragon, sf::RectangleShape& healthBarDragon) {
        for (auto& meteorite : meteorites) {
            if (meteorite->getIsAlive()) {
                meteorite->update(deltaTime, dragon, healthBarDragon);
            }
        }
    }
};