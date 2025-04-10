///This game is reccommended to be played in 1280x800 resolution.
#include "Player.h"
#include "Entity.h"
#include "Attack.h"
#include "Monster.h"

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 800), "WayToTheGlory", sf::Style::Default);
    
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Textures/Background.jpg")) {
        return -1;
    }

    sf::Sprite backgroundSprite(backgroundTexture);

    sf::Vector2u textureSize = backgroundTexture.getSize();
    sf::Vector2u windowSize = window.getSize();
    backgroundSprite.setScale(
        float(windowSize.x) / textureSize.x,
        float(windowSize.y) / textureSize.y
    );

    sf::Texture playerTexture;
    playerTexture.loadFromFile("Textures/Warrior_texture_pack_transparent-background.png");
    Player player(&playerTexture, sf::Vector2u(7,4), 0.1f, 100.f, 200.f, 400.f, 100.f, 65.f);
    Attack playerAttack(player, 2, 150.f);

    sf::Texture dragonTexture;
    dragonTexture.loadFromFile("Textures/Dragon_texture_pack_transparent_background.png");
    Monster dragon(&dragonTexture, sf::Vector2u(7,5), .2f, 30.f, 1100.f, 400.f, 300.f, 150.f);

    float deltaTime = 0.f;
    sf::Clock clock;

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

        playerAttack.Update(deltaTime);
        player.Update(deltaTime, playerAttack);

        dragon.Update(deltaTime, player);

        // window.clear(sf::Color::Black);
        window.draw(backgroundSprite);

        player.Draw(window);
        dragon.Draw(window);
        
        window.display();
    }
    
    return 0;
}
