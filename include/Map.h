#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>

class Map
{
    public:
        Map(sf::Texture* texture, float scale, float movement_speed, int mirrorReflection,sf::RenderWindow* window);
        virtual ~Map();
        float movementSpeed;
        void update();
        void render(sf::RenderTarget* target);

    protected:

    private:
        sf::Vector2f backgroundPosition;
        float yWindowPos;
        sf::RenderWindow* window;
        sf::Sprite backgroundSprite1;
        sf::Sprite backgroundSprite2;
        sf::Texture backgroundTexture1;
        sf::Texture backgroundTexture2;
};

#endif // MAP_H
