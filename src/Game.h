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

        void init() {
            window.create(sf::VideoMode(600, 600), "game");
            window.setFramerateLimit(60);
            paused = false;
            running = true;
            player = eMan.addEntity().get();
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
                window.clear();
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