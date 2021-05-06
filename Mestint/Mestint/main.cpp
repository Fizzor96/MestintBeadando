#include <SFML/Graphics.hpp>
#include "Hanoi.h"
#include "Globals.h"


int main()
{
    //Setup
    sf::RenderWindow window(sf::VideoMode(Global::Width, Global::Height), "Mestint Beadando");
    window.setFramerateLimit(300);
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
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Space)
            {
                h->Reset();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::A)
            {
                std::thread t1(&Hanoi::DepthSearch, h);
                t1.detach();
                t1.~thread();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::S)
            {
                std::thread t1(&Hanoi::BackTrack, h);
                t1.detach();
                t1.~thread();
            }
        }
        window.clear(sf::Color(128, 128, 128, 255));
        //Draw here
        h->Draw(window);
        window.display();
    }
    return 0;
}