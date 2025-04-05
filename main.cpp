///This game is reccommended to be played in 1280x800 resolution.
#include "Animation.h"

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 800), "WayToTheGlory", sf::Style::Default);

    sf::RectangleShape player(sf::Vector2f(100.f, 65.f));

    sf::Texture playerTexture;
    playerTexture.loadFromFile("Textures/Warrior_texture_pack_transparent-background.png");
    player.setTexture(&playerTexture);

    ///Animation playerAnimation(&playerTexture, textureSize, 0.1f);
    Animation playerAnimation(&playerTexture, sf::Vector2u(7,6), 0.1f);

    float deltaTime = 0.f;
    sf::Clock clock;

    // player.setFillColor(sf::Color::Green);
    player.setPosition(640.f, 400.f);
    player.setOrigin(player.getSize().x / 2, player.getSize().y / 2);

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                
                default:
                    break;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player.getPosition().y -37.5 > 0.f)
            player.move(0.f, -0.1f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && player.getPosition().x -50 > 0.f)
            player.move(-0.1f, 0.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && player.getPosition().y + 37.5 < window.getSize().y)
            player.move(0.f, 0.1f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && player.getPosition().x + 50 < window.getSize().x)
            player.move(0.1f, 0.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();

        playerAnimation.Update(0, deltaTime);
        player.setTextureRect(playerAnimation.getUVRect());

        window.clear(sf::Color::Black);
        window.draw(player);
        window.display();
    }
    
    return 0;
}
