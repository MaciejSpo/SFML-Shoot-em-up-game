#ifndef HEAL_H
#define HEAL_H
#include<SFML/Graphics.hpp>
#include "Boost.h"
#include "TextureManager.h"

class Heal : public Boost
{
    public:
        Heal(float pos_x, float pos_y,TextureManager& textureManager);
        virtual ~Heal();

    protected:

    private:
        sf::Texture healTexture;
        virtual void update();
        void render(sf::RenderTarget* target);
        virtual void initVariables();
        virtual void initSprite();
        std::vector<Boost*> boosts;
        sf::Clock clock;
        int healPoints;
};

#endif // HEAL_H
