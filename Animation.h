#pragma once

#include <SFML/Graphics.hpp>

class Animation
{
    sf::Vector2u imageCount;
    sf::Vector2u currentImage;

    float totalTime;
    float switchTime;

    sf::IntRect uvRect;

public:
    Animation(sf::Texture *, sf::Vector2u, float);
    Animation(const Animation &);
    virtual ~Animation();

    const sf::IntRect getUVRect() const;
    const sf::Vector2u getImageCount() const;
    const sf::Vector2u getCurrentImage() const;

    void setUVRect(const sf::IntRect &);

    void Update(int, float, bool);
};