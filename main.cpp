///This game is reccommended to be played in 1280x800 resolution.
#include "Player.h"

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 800), "WayToTheGlory", sf::Style::Default);

    sf::Texture playerTexture;
    playerTexture.loadFromFile("Textures/Warrior_texture_pack_transparent-background.png");

    Player player(&playerTexture, sf::Vector2u(7,4), 0.1f, 100.f);

    float deltaTime = 0.f;
    sf::Clock clock;

    // player.setOrigin(player.getSize().x / 2, player.getSize().y / 2);

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
                
                case sf::Event::KeyPressed:
                    if (evnt.key.code == sf::Keyboard::Escape)
                        window.close();
                    break;
                
                default:
                    break;
            }
        }

        player.Update(deltaTime);

        window.clear(sf::Color::Black);
        player.Draw(window);
        window.display();
    }
    
    return 0;
}
