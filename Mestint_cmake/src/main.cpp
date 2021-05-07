#include <SFML/Graphics.hpp>
#include "Hanoi.h"
#include "Globals.h"


int main()
{
    //Setup
    sf::RenderWindow window(sf::VideoMode(Global::Width, Global::Height), "Mestint Beadando");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(false);
    window.setPosition(sf::Vector2i(((sf::VideoMode::getDesktopMode().width / 2) - (window.getSize().x / 2)), ((sf::VideoMode::getDesktopMode().height / 2) - (window.getSize().y / 2))));
    
    Hanoi* h = new Hanoi();
    std::thread t1(&Hanoi::DepthSearchInit, h);
    t1.detach();
    t1.~thread();

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

            //mozgat gombok
            /*if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Q)
            {
                h->Mozgat('A', 'B');
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::W)
            {
                h->Mozgat('A', 'C');
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::E)
            {
                h->Mozgat('B', 'A');
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::R)
            {
                h->Mozgat('B', 'C');
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::T)
            {
                h->Mozgat('C', 'A');
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Z)
            {
                h->Mozgat('C', 'B');
            }*/
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Space)
            {
                h->Reset();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::S)
            {
                std::thread t4(&Hanoi::DepthSearch, h);
                t4.detach();
                t4.~thread();
            }
        }
        window.clear(sf::Color(128, 128, 128, 255));
        //Draw here
        h->Draw(window);
        window.display();
    }
    return 0;
}