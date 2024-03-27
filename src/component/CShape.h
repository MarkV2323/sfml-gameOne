#pragma once

#include <SFML/Graphics/CircleShape.hpp>

namespace game {
    class CShape
    {
    private:
        CShape() {}
    public:
        sf::CircleShape shape {};
        
        CShape(float r, int points, const sf::Color& fill, const sf::Color& outline, float thickness)
            : shape(r, points) {
                shape.setFillColor(fill);
                shape.setOutlineColor(outline);
                shape.setOutlineThickness(thickness);
                shape.setOrigin(r, r);
            }
        ~CShape() {}
    };
}