#include <SFML/Graphics.hpp>
#include <time.h>
#include "settings.h"
#include "programs.h"

using namespace sf;

int main()
{
    srand(time(0));

    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Welcome to the Grid!");
    window.setFramerateLimit(60);
	
    Texture texture;
    texture.loadFromFile("TRONGAME.jpg");
    Sprite sBackground(texture);

    Program p1(Color::Blue), p2(Color::Red); 

    Sprite sprite;

    RenderTexture t;
    t.create(WIDTH, HEIGHT);
    t.setSmooth(true);

    sprite.setTexture(t.getTexture());
    t.clear();  
	t.draw(sBackground);

    bool game = true;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left));
		else if (p1.dir != 2) p1.dir = 1;

        if (Keyboard::isKeyPressed(Keyboard::Right));
		else if (p1.dir != 1)  p1.dir = 2;

        if (Keyboard::isKeyPressed(Keyboard::Up)); 
		else if (p1.dir != 0) p1.dir = 3;

        if (Keyboard::isKeyPressed(Keyboard::Down)); 
		else if (p1.dir != 3) p1.dir = 0;

        if (Keyboard::isKeyPressed(Keyboard::A)); 
		else if (p2.dir != 2) p2.dir = 1;

        if (Keyboard::isKeyPressed(Keyboard::D)); 
		else if (p2.dir != 1)  p2.dir = 2;

        if (Keyboard::isKeyPressed(Keyboard::W)); 
		else if (p2.dir !=0 ) p2.dir = 3;

        if (Keyboard::isKeyPressed(Keyboard::S)); 
		else if (p2.dir !=3 ) p2.dir = 0;

        for(int i=0;i< SPEED;i++)
        {
            p1.tick(); 
			p2.tick();
            if (field[p1.x][p1.y] == 1) 
			{
				game = false; 
			}
			
            if (field[p2.x][p2.y] == 1)
			{
				game = false;
			} 

            field[p1.x][p1.y] = 1; 
            field[p2.x][p2.y] = 1;
    
            CircleShape c(3);

            c.setPosition(p1.x, p1.y); 
			c.setFillColor(p1.color);    
			t.draw(c);

            c.setPosition(p2.x, p2.y); 
			c.setFillColor(p2.color);    
			t.draw(c);

            t.display();    
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
