/// This game is reccommended to be played in 1280x800 resolution.
/// Try to beat the dragon by attacking it with your spear and dodging its fireball attacks.
/// You have approximately 3seconds to attack until the dragon attacks you with its fireball since you can attack him.
#include "Player.h"
#include "Entity.h"
#include "Attack.h"
#include "Monster.h"
#include "Meteorite.h"
#include "GameManager.h"
#include "ExceptionTypes.h"

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

template <typename PtrVector, typename Lambda>
void removeIfPtr(PtrVector& vec, Lambda condition)
{
    for (auto it = vec.begin(); it != vec.end(); )
    {
        if (condition(*it))
        {
            delete *it;
            it = vec.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

int main()
{
    try
    {
        sf::RenderWindow window(sf::VideoMode(1280, 800), "WayToTheGlory", sf::Style::Default);

        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("Textures/Background.jpg"))
        {
            throw FileLoadException("Textures/Background.jpg");
        }

        sf::Sprite backgroundSprite(backgroundTexture);

        sf::Vector2u textureSize = backgroundTexture.getSize();
        sf::Vector2u windowSize = window.getSize();
        backgroundSprite.setScale(
            float(windowSize.x) / textureSize.x,
            float(windowSize.y) / textureSize.y);

        sf::Texture playerTexture;
        if (!playerTexture.loadFromFile("Textures/Warrior_texture_pack_transparent-background.png"))
            throw FileLoadException("Textures/Warrior_texture_pack_transparent-background.png");
        Player player = Player::getPlayer(&playerTexture, sf::Vector2u(7, 4), 0.1f, 100.f, 200.f, 400.f, 100.f, 65.f, 100, 100);
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
        if (!dragonTexture.loadFromFile("Textures/Dragon_texture_pack_transparent_background.png"))
            throw FileLoadException("Textures/Dragon_texture_pack_transparent_background.png");
        Monster dragon(&dragonTexture, sf::Vector2u(7, 5), .2f, 30.f, 1100.f, 400.f, 300.f, 150.f, 500, 500, false);
        MonsterAttack dragonAttack(dragon, 2, 150.f, 150.f, 50.f, 0.7f, 0.f, 40.f, 30.f, 10.f, 10);

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

        sf::Texture meteoriteTexture;
        if (!meteoriteTexture.loadFromFile("Textures/Meteorite.png"))
            throw FileLoadException("Textures/Meteorite.png");
        Meteorite *meteorite = new Meteorite(&meteoriteTexture, sf::Vector2u(1, 1), 0.1f, 100.f, 200.f, 400.f, 30.f, 50.f, 30, 30, 5.f, 0.f, 60.f, 0.f);

        GameManager<Meteorite> &gameManager = GameManager<Meteorite>::getGameManager();

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

            playerAttack.Update(deltaTime, dragon, healthBarDragon, gameManager.getMeteorites());
            player.Update(deltaTime, playerAttack);

            dragon.Update(deltaTime, player, dragonAttack, 100.f, 90.f, 50.f, 10.f, healthBar);

            meteorite->spown(deltaTime, gameManager);

            gameManager.updateMeteorites(deltaTime, dragon, healthBarDragon);

            window.draw(backgroundSprite);

            player.Draw(window);

            dragon.Draw(window, dragonAttack);

            window.draw(healthBarOutline);
            window.draw(healthBar);

            window.draw(healthBarOutlineDragon);
            window.draw(healthBarDragon);

            for (auto &meteorite : gameManager.getMeteorites())
                meteorite->draw(window);

            if (dragon.getHealth() <= 0.f || player.getHealth() <= 0.f)
                break;

            window.display();
        }

        if (dragon.getHealth() <= 0.f)
        {
            sf::Font font;
            if (!font.loadFromFile("Fonts/arial.ttf"))
            {
                std::cerr << "Failed to load font!" << std::endl;
                return -1;
            }

            sf::Text victoryText;
            victoryText.setFont(font);
            victoryText.setString("You have defeated the dragon!");
            victoryText.setCharacterSize(50);
            victoryText.setFillColor(sf::Color::White);
            victoryText.setStyle(sf::Text::Bold);
            victoryText.setPosition(250.f, 350.f);

            while (window.isOpen())
            {
                sf::Event evnt;
                while (window.pollEvent(evnt))
                {
                    if (evnt.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                        window.close();
                }

                window.clear();
                window.draw(victoryText);
                window.display();
            }
        }
        else if (player.getHealth() <= 0.f)
        {
            sf::Font font;
            if (!font.loadFromFile("Fonts/arial.ttf"))
            {
                std::cerr << "Failed to load font!" << std::endl;
                return -1;
            }

            sf::Text defeatText;
            defeatText.setFont(font);
            defeatText.setString("You have been defeated by the dragon!");
            defeatText.setCharacterSize(50);
            defeatText.setFillColor(sf::Color::Red);
            defeatText.setStyle(sf::Text::Bold);
            defeatText.setPosition(250.f, 350.f);

            while (window.isOpen())
            {
                sf::Event evnt;
                while (window.pollEvent(evnt))
                {
                    if (evnt.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                        window.close();
                }

                window.clear();
                window.draw(defeatText);
                window.display();
            }
        }
    }
    catch (const FileLoadException &e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    catch (const InvalidEntityException &e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    catch (const StateException &e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    return 0;
}
