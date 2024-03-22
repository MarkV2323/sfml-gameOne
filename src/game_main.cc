#include <iostream>
#include <SFML/Graphics.hpp>

#include "entities/Entity.h"

using namespace std;
using namespace game;

int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "game");
    window.setFramerateLimit(60);

    auto e = Entity();
    cout << e.printEntityInfo() << "\n";
    e.cScore = std::make_shared<CScore>(5);
    cout << e.printEntityInfo() << "\n";
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.scancode == sf::Keyboard::Scan::Escape)
                window.close();
        }
        window.clear();
        window.display();
    }
    return 0;
}