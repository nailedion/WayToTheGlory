#include "Animation.h"

#include <SFML/Graphics.hpp>

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.f;
    currentImage.x = 0;
    currentImage.y = 0;

    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);
}

sf::IntRect Animation::getUVRect() const {
    return uvRect;
}

void Animation::setUVRect(const sf::IntRect& rect) {
    uvRect = rect;
}

void Animation::Update(int row, float deltaTime) ///, bool faceRight, bool isMoving
{
    currentImage.y =row;
    totalTime += deltaTime;

    if(totalTime >= switchTime)
    {
        totalTime -= switchTime;
        currentImage.x++;
        if (currentImage.x >= imageCount.x)
            currentImage.x = 0;
    }

    uvRect.left = currentImage.x * uvRect.width;
    uvRect.top = currentImage.y * uvRect.height;
}

Animation::~Animation()
{
}