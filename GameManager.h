#include "Entity.h"
#include "Monster.h"

#include <SFML/Graphics.hpp>
#include <vector>

class GameManager {
protected:
    std::vector<Entity*> meteorites;

public:
    void operator=(GameManager& other) {
        if (this != &other) {
            swap(meteorites, other.meteorites);
        }
    }

    friend void swap(GameManager& first, GameManager& second) {
        std::swap(first.meteorites, second.meteorites);
    }

    GameManager() = default;
    GameManager(const GameManager& other) {
        for (const auto& meteorite : other.meteorites) {
            meteorites.push_back(meteorite->clone()); // Assuming clone() creates a deep copy
        }
    }
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
            delete *it;
            meteorites.erase(it, meteorites.end());
        }
    }

    void updateMeteorites(float deltaTime, Monster& dragon, sf::RectangleShape& healthBarDragon) {
        for (auto& meteorite : meteorites) {
            if (meteorite->getIsAlive()) {
                meteorite->update(deltaTime, dragon, healthBarDragon);
            }

            if (Meteorit* metheorite = dynamic_cast<Meteorit*>(meteorite)) {
                metheorite->killIfCollides(dragon);
            }
        }
    }
};