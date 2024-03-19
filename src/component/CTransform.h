#pragma once

#include <SFML/System/Vector2.hpp>

namespace game {
    class CTransform {
    public:
        sf::Vector2f pos {0.0, 0.0};
        sf::Vector2f speed {0.0, 0.0};
        sf::Vector2f scale {0.0, 0.0};
        double angle {0.0};

        CTransform() : pos(sf::Vector2f(0.0, 0.0)), 
            speed(sf::Vector2f(0.0, 0.0)), 
            scale(sf::Vector2f(0.0, 0.0)), 
            angle(0.0) {}
        ~CTransform() {}
    };
}