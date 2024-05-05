#ifndef TWOBULLETS_H
#define TWOBULLETS_H
#include "Boost.h"
#include "TextureManager.h"
class TwoBullets : public Boost
{
    public:
        TwoBullets(float pos_x, float pos_y,TextureManager& textureManager);
        virtual ~TwoBullets();

    protected:

    private:
        sf::Texture healTexture;
        virtual void update();
        void render(sf::RenderTarget* target);
        virtual void initVariables();
        virtual void initSprite();
        std::vector<Boost*> boosts;
        sf::Clock clock;
};

#endif // TWOBULLETS_H
