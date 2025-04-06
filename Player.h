#include "Animation.h"

#include <SFML/Graphics.hpp>

class Player
{
        sf::RectangleShape body;
        Animation animation;
        unsigned int row;
        float speed;
        bool faceRight;

    public:
        Player(sf::Texture*, sf::Vector2u, float, float);
        ~Player();

        void Update(float deltaTime);
        void Draw(sf::RenderWindow&);
};