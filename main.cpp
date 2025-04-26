///This game is reccommended to be played in 1280x800 resolution.
///Try to beat the dragon by attacking it with your spear and dodging its fireball attacks.
///You have approximately 3seconds to attack until the dragon attacks you with its fireball since you can attack him.
#include "Player.h"
#include "Entity.h"
#include "Attack.h"
#include "Monster.h"

#include <iostream>
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
    Player player(&playerTexture, sf::Vector2u(7,4), 0.1f, 100.f, 200.f, 400.f, 100.f, 65.f, 100, 100);
    Attack playerAttack(player, 2, 150.f, 10, 0.0f, 0.5f);

    sf::RectangleShape healthBar;
    healthBar.setSize(sf::Vector2f(200.f, 20.f));
    healthBar.setFillColor(sf::Color::Red);
    healthBar.setPosition(10.f, 10.f);
    sf::RectangleShape healthBarOutline;
    healthBarOutline.setSize(sf::Vector2f(200.f, 20.f));
    healthBarOutline.setFillColor(sf::Color::Transparent);
    healthBarOutline.setOutlineThickness(2.f);
    healthBarOutline.setOutlineColor(sf::Color::Black);
    healthBarOutline.setPosition(10.f, 10.f);

    sf::Texture dragonTexture;
    dragonTexture.loadFromFile("Textures/Dragon_texture_pack_transparent_background.png");
    Monster dragon(&dragonTexture, sf::Vector2u(7,5), .2f, 30.f, 1100.f, 400.f, 300.f, 150.f, 100, 100, false);
    MonsterAttack dragonAttack(dragon, 2, 150.f, 150.f, 50.f, 0.7f,0.f, 40.f, 30.f, 10.f, 10);

    sf::RectangleShape healthBarDragon;
    healthBarDragon.setSize(sf::Vector2f(200.f, 20.f));
    healthBarDragon.setFillColor(sf::Color::Red);
    healthBarDragon.setPosition(1070.f, 10.f);
    sf::RectangleShape healthBarOutlineDragon;
    healthBarOutlineDragon.setSize(sf::Vector2f(200.f, 20.f));
    healthBarOutlineDragon.setFillColor(sf::Color::Transparent);
    healthBarOutlineDragon.setOutlineThickness(2.f);
    healthBarOutlineDragon.setOutlineColor(sf::Color::Black);
    healthBarOutlineDragon.setPosition(1070.f, 10.f);

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

        playerAttack.Update(deltaTime, dragon, healthBarDragon);
        player.Update(deltaTime, playerAttack);
        
        dragon.Update(deltaTime, player, dragonAttack, 100.f, 90.f,50.f,10.f, healthBar);

        window.draw(backgroundSprite);

        player.Draw(window);
        // playerAttack.Draw(window);
        
        dragon.Draw(window, dragonAttack);
        
        window.draw(healthBarOutline);
        window.draw(healthBar);

        window.draw(healthBarOutlineDragon);
        window.draw(healthBarDragon);

        window.display();
    }
    
    return 0;
}
