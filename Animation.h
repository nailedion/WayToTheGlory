#pragma once

#include <SFML/Graphics.hpp>

class Animation
{
        sf::Vector2u imageCount;
        sf::Vector2u currentImage;

        float totalTime;
        float switchTime;

        sf::IntRect uvRect; ///public???

    public:
        Animation(sf::Texture*, sf::Vector2u, float);
        ~Animation();

        sf::IntRect getUVRect() const;

        void setUVRect(const sf::IntRect&);

        void Update(int, float, bool);
};