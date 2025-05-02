#include "Animation.h"

#include <SFML/Graphics.hpp>

Animation::Animation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime)
{
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.f;
    currentImage.x = 0;
    currentImage.y = 0;

    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);
}

Animation::Animation(const Animation &animation) : imageCount(animation.imageCount),
                                                   currentImage(animation.currentImage),
                                                   totalTime(animation.totalTime),
                                                   switchTime(animation.switchTime),
                                                   uvRect(animation.uvRect)
{
}

const sf::IntRect Animation::getUVRect() const
{
    return uvRect;
}

const sf::Vector2u Animation::getImageCount() const
{
    return imageCount;
}

const sf::Vector2u Animation::getCurrentImage() const
{
    return currentImage;
}

void Animation::setUVRect(const sf::IntRect &rect)
{
    uvRect = rect;
}

void Animation::Update(int row, float deltaTime, bool faceRight)
{
    currentImage.y = row;
    totalTime += deltaTime;

    if (totalTime >= switchTime)
    {
        totalTime -= switchTime;
        currentImage.x++;
        if (currentImage.x >= imageCount.x)
            currentImage.x = 0;
    }

    uvRect.top = currentImage.y * uvRect.height;
    if (faceRight)
    {
        uvRect.left = currentImage.x * uvRect.width;
        uvRect.width = abs(uvRect.width);
    }
    else
    {
        uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);
    }
}

Animation::~Animation()
{
}