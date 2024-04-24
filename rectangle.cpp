#include "Rectangle.hpp"

Rectangle::Rectangle(Vector2f size)
{
    this->shape = RectangleShape(size);
    this->shape.setFillColor(Color::Green);
    this->speed  = Vector2f(3.f,3.f);
    this->acc = Vector2f(0.f,1.f);
}

Rectangle::Rectangle(Vector2f size, int x, int y)
{
    this->shape = RectangleShape(size);
    this->shape.setFillColor(Color::Green);
    this->shape.setPosition(Vector2f (x,y));
    this->speed  = Vector2f(3.f,3.f);
    this->acc = Vector2f(0.f,1.f);
}

void Rectangle::update()
{
    this->speed += this->acc;
    this->shape.move(speed);

    //this->shape.setPosition(position + this->speed);

     if(this->shape.getPosition().x + this->shape.getSize().x >= 800 || this->shape.getPosition().x < 0)
     {
        this->speed.x *= -1;
     }
        
     if(this->shape.getPosition().y + this->shape.getSize().y >= 600 || this->shape.getPosition().y < 0)
     {
        this->speed.y *= -1;
        Vector2f position = this -> shape.getPosition();
        this->shape.setPosition(position.x, 600 - this->shape.getSize().y);
     }
}

void Rectangle::drawTo(RenderWindow &window)
{
    window.draw(this->shape);
}

void Rectangle::click(int x, int y)
{
    bool checkx = false;
    bool checky = false;

    if(x > this->shape.getPosition().x && x < this->shape.getPosition().x + this->shape.getSize().x)
    checkx = true;

    if(y > this->shape.getPosition().y && y < this->shape.getPosition().y + this->shape.getSize().y)
    checky = true;

    if(checkx && checky)
    this->shape.setFillColor(Color::Blue);
}