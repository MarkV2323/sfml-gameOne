#pragma once

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

        void init() {}

        void sMovement() {}

        void sUserInput() {}

        void sRender() {}

        void sEnemySpawner() {}

        void sCollision() {}
        
    public:
        Game() {};
        ~Game() {};

        void update() {}
    };
    
}