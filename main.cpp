#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Window name");
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                // Close window button clicked.
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        // Draw here.
        window.display();
    }

    return 0;
}