#include <SFML/Graphics.hpp>
#include "Hanoi.h"


int main()
{
    //Setup
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Mestint Beadando");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(false);
    window.setPosition(sf::Vector2i(((sf::VideoMode::getDesktopMode().width / 2) - (window.getSize().x / 2)), ((sf::VideoMode::getDesktopMode().height / 2) - (window.getSize().y / 2))));
    
    
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