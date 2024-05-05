#ifndef EXPLOSION_H
#define EXPLOSION_H
#include "TextureManager.h"
#include <iostream>

class Explosion
{
    public:
        Explosion(float pos_x, float pos_y,TextureManager& textureManager,int type);
        virtual ~Explosion();
        void update();
        void render(sf::RenderTarget* target);
        bool deleteExplosion;
    protected:

    private:
        float switchTextureMax;
        float switchTexture;
        float pos_x, pos_y;
        sf::Texture explosion1;
        sf::Texture explosion2;
        sf::Texture explosion3;
        sf::Texture explosion4;
        sf::Texture explosion5;
        sf::Texture explosion6;
        sf::Sprite sprite;
};

#endif // EXPLOSION_H
