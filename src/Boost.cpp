#include "Boost.h"

Boost::Boost(float pos_x,float pos_y, TextureManager& textureManager)
{
}

Boost::~Boost()
{
}

void Boost::initVariables()
{
}

void Boost::initSprite()
{
}

void Boost::update()
{
    this->sprite.move(0.f,this->speed);
}

const sf::FloatRect Boost :: getBounds() const
{
    return this->sprite.getGlobalBounds();
}
const sf::Vector2f& Boost::getPos() const{
    return this -> sprite.getPosition();
}

void Boost::render(sf::RenderTarget* target)
{
    target->draw(this->sprite);
}

