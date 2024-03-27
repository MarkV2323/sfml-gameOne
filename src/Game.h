#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

#include "entities/EntityManager.h"

namespace game {
    class Game
    {
    private:
        sf::RenderWindow window {};
        EntityManager eMan {};
        Entity* player {nullptr};
        bool paused {false};
        bool running {false};
        bool playerSpawned {false};

        void init() {
            window.create(sf::VideoMode(600, 600), "game");
            window.setFramerateLimit(60);
            paused = false;
            running = true;
            player = eMan.addEntity("player").get();
            float playerRadius = 20;
            player->cInput = std::make_shared<CInput>();
            player->cScore = std::make_shared<CScore>(0);
            player->cShape = std::make_shared<CShape>(playerRadius, 60, sf::Color::Blue, sf::Color::White, 2.0f);
            player->cCollision = std::make_shared<CCollision>(playerRadius);
            player->cTransform = std::make_shared<CTransform>(sf::Vector2f(300.0f, 300.0f), sf::Vector2f(3.0f, 3.0f), sf::Vector2f(2.0f, 2.0f), 2.0f);
            player->cShape.get()->shape.setPosition(player->cTransform.get()->pos);
        }

        void sMovement() {

        }

        // Handle user input
        void sUserInput() {
            if (window.isOpen()) {
                sf::Event event;
                if (!window.pollEvent(event))
                    return;
                if (event.type == sf::Event::Closed) {
                    running = false;
                    window.close();
                }
                if (event.type == sf::Event::KeyPressed && event.key.scancode == sf::Keyboard::Scan::Escape) {
                    running = false;
                    window.close();
                }
                if (event.type == sf::Event::KeyPressed && event.key.scancode == sf::Keyboard::Scan::P) {
                    (paused) ? paused = false : paused = true;
                    std::cout << "\nGame Paused: " << std::boolalpha << paused << "\n";
                    std::cout << eMan.getEntitiesStats() << "\n\n";
                }
            }
        }

        // Handle rendering
        void sRender() {
            if (window.isOpen()) {
                window.clear(sf::Color::Black);
                for (auto& entity : eMan.getEntities()) {
                    if (entity.get()->cShape) {
                        window.draw(entity.get()->cShape.get()->shape);
                    }
                }
                window.display();
            }
        }

        void sEnemySpawner() {

        }

        void sCollision() {

        }

    public:
        Game() {
            init();
        };
        ~Game() {};

        void update() {
            // One "frame" of our game.
            if (paused) {
                sUserInput();
                return;
            }
            eMan.update();
            sEnemySpawner();
            sUserInput();
            sMovement();
            sCollision();
            sRender();
        }

        bool isRunning() {
            return running;
        }

        bool isPaused() {
            return paused;
        }
    };
    
}