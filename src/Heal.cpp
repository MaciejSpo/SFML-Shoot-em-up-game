#include "Heal.h"

Heal::Heal(float pos_x, float pos_y,TextureManager& textureManager) : Boost(pos_x, pos_y, textureManager)
{
    this->sprite.setTexture(textureManager.getTexture("heart"));
    this->initVariables();
    this->initSprite();
    this->sprite.setPosition(pos_x, pos_y);
}

Heal::~Heal()
{

    //dtor
}

void Heal::initVariables(){
    this->healPoints = 5;
    this->speed = 2.f;
    this->type = 1;
}

void Heal::initSprite(){
    sprite.scale(0.12f,0.12f);
}

void Heal::update()
{
    this->sprite.move(0.f,this->speed);
}
