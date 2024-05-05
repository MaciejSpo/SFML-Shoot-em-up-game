#include "Clouds.h"
Clouds::Clouds(sf::Texture* texture, float pos_x, float pos_y, float scale,float movement_speed, int mirrorReflection)
{
    this -> movementSpeed = movement_speed;
    this -> shape.setTexture(*texture);
    this->shape.setScale(scale,scale);
    this -> shape.setPosition(pos_x,pos_y);
    this -> movementSpeed = movement_speed;
    if(mirrorReflection) shape.setScale(scale,-1.f*scale);
}

Clouds::~Clouds()
{
}

const sf::FloatRect Clouds::getBounds() const
{
    return this -> shape.getGlobalBounds();
}

void Clouds::update()
{
    this -> shape.move(-0.f,this->movementSpeed);
}

void Clouds::render(sf::RenderTarget* target)
{
    target -> draw(this->shape);
}
