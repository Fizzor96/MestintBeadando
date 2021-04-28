#include <SFML/Graphics.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::RectangleShape* rect = new sf::RectangleShape(sf::Vector2f(40.f, 40.f));
    rect->setFillColor(sf::Color::Green);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(*rect);
        window.display();
    }
    return 0;
}