#include "TwoBullets.h"

TwoBullets::TwoBullets(float pos_x, float pos_y,TextureManager& textureManager) : Boost(pos_x, pos_y, textureManager)
{
    this->sprite.setTexture(textureManager.getTexture("twobullets"));
    this->initVariables();
    this->initSprite();
    this->sprite.setPosition(pos_x, pos_y);
}

TwoBullets::~TwoBullets()
{
    //dtor
}

void TwoBullets::initVariables(){
    this->speed = 2.f;
    this->type = 2;
}

void TwoBullets::initSprite(){
    sprite.scale(0.10f,0.10f);
}

void TwoBullets::update()
{
    this->sprite.move(0.f,this->speed);
}
