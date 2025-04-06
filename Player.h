#include "Animation.h"
#include "Entity.h"

#include <SFML/Graphics.hpp>

class Player: public Entity
{

    public:
        Player(Entity&);
        ~Player();

        void Update(float deltaTime);
        void Draw(sf::RenderWindow&);
};