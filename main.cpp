#include <SFML/Graphics.hpp>
using namespace sf;
#include "rectangle.hpp"
#include <vector>
using namespace std;

/*struct vector2f
{
    int x;
    int y;
};*/

Vector2f speed = {5.f, 5.f};

int main()
{
    RenderWindow window(VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(60);
    Rectangle shape(Vector2f(50.f,20.f));
    vector<Rectangle> rectangulos;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if(event.type == Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == Mouse::Left)
                {
                    int w = rand()%50;
                    int h = rand()%50;
                    int x = event.mouseButton.x;
                    int y = event.mouseButton.y;

                    Rectangle rec(Vector2f(w,h), x, y);
                    rectangulos.push_back(rec);
                }

                if(event.mouseButton.button == Mouse::Right)
                {
                    int x = event.mouseButton.x;
                    int y = event.mouseButton.y;
                    for(auto &r : rectangulos)
                    {
                        r.click(x,y);
                    }
                }
            }

        }

        window.clear();
        shape.update();
        shape.drawTo(window);

        for(auto &r : rectangulos)
        {
            r.update();
            r.drawTo(window);
        }

        window.display();
    }

    return 0;
}