#include "Animation.h"
#include "Entity.h"
#include "Player.h"
#include "Attack.h"

#include <SFML/Graphics.hpp>

class Monster: public Entity
{
    public:
    Monster(sf::Texture*, sf::Vector2u, float, float, float, float, float, float);
    ~Monster();

    void Update(float, Player&);

    void Draw(sf::RenderWindow&);
};