#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet
{
    public:
        Bullet();
        Bullet(sf::Texture* texture, float pos_x, float pos_y, float dir_x,float dir_y,float movement_speed);
        Bullet(sf::Texture* texture, float pos_x, float pos_y, float dir_x,float dir_y,float movement_speed, float damage);
        virtual ~Bullet();
        float damage;
        // Accessor
        const sf::FloatRect getBounds() const;
        void update();
        void render(sf::RenderTarget* target);
    protected:

    private:
        sf::Sprite shape;
        sf::Vector2f direction;
        float movementSpeed;

};

#endif // BULLET_H
