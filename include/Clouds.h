#ifndef CLOUDS_H
#define CLOUDS_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Clouds
{
    public:
        Clouds(sf::Texture* texture, float pos_x, float pos_y, float scale,float movement_speed,int mirrorReflection);
        virtual ~Clouds();
        sf::Sprite shape;
        float movementSpeed;
        const sf::FloatRect getBounds() const;
        void update();
        void render(sf::RenderTarget* target);

    protected:

    private:
};

#endif // CLOUDS_H
