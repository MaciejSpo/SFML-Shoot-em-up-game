#include "Explosion.h"

Explosion::Explosion(float pos_x, float pos_y,TextureManager& textureManager, int type)
{
    this->pos_x=pos_x;
    this->pos_y=pos_y;
    this->sprite.setPosition(this->pos_x+15.f, this->pos_y+20.f);
    this->explosion1=textureManager.getTexture("Explosion1");
    this->explosion2=textureManager.getTexture("Explosion2");
    this->explosion3=textureManager.getTexture("Explosion3");
    this->explosion4=textureManager.getTexture("Explosion4");
    this->explosion5=textureManager.getTexture("Explosion5");
    this->explosion6=textureManager.getTexture("Explosion6");
    this->sprite.setTexture(this->explosion1);
    this->deleteExplosion=false;
    this->switchTexture=12.f;
    if (type<=3)
        this->sprite.setScale(0.4,0.4);
    if (type==4)
        this->sprite.setScale(0.7,0.7);
    if (type==5)
        this->sprite.setScale(2.0,2.0);
}

Explosion::~Explosion()
{
    //dtor
}

void Explosion::update()
{
    this->switchTexture-=0.2f;
    if(this->switchTexture>=10.f)
        this->sprite.setTexture(this->explosion2);
    else if(this->switchTexture>=8.f)
        this->sprite.setTexture(this->explosion3);
    else if(this->switchTexture>=6.f)
        this->sprite.setTexture(this->explosion4);
    else if(this->switchTexture>=4.f)
        this->sprite.setTexture(this->explosion5);
    else if(this->switchTexture>=2.f)
        this->sprite.setTexture(this->explosion6);
    else if(this->switchTexture>=0.f)
        this->deleteExplosion=true;
}

void Explosion::render(sf::RenderTarget* target)
{
    target -> draw(this->sprite);
}

