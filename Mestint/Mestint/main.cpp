#include <SFML/Graphics.hpp>
#include "Hanoi.h"


int main()
{
    //Setup
    sf::RenderWindow window(sf::VideoMode(800, 600), "Mestint Beadando");
    window.setFramerateLimit(60);
    window.setSize(sf::Vector2u(1280, 1024));
    window.setVerticalSyncEnabled(false);

    Hanoi* h = new Hanoi();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Escape)
            {
                window.close();
            }
        }
        window.clear();
        //Draw here
        h->Draw(window);
        window.display();
    }
    return 0;
}