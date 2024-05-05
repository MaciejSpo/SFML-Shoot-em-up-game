#ifndef BOOST_H
#define BOOST_H
#include "TextureManager.h"
#include<SFML/Graphics.hpp>
class Boost
{
    public:
        Boost(float pos_x,float pos_y, TextureManager& textureManager);
        virtual ~Boost();
        const sf::FloatRect getBounds() const;
        const sf::Vector2f& getPos() const;
        virtual void update();
        void render(sf::RenderTarget* target);
        int type;
    protected:
        virtual void initVariables();
        virtual void initSprite();
        sf::Sprite sprite;
        float speed;
    private:
};

#endif // BOOST_H
