#ifndef FW190_H
#define FW190_H
#include "Enemy.h"
#include "TextureManager.h"
#include "Bullet.h"
class FW190 : public Enemy
{
    public:
        FW190(float pos_x, float pos_y,TextureManager& textureManager,std::vector<Bullet*>& bullets);
        virtual ~FW190();
        void shoot();
        void loseHp(int dmg);
    protected:
    private:
        sf::Texture FW190Hitted;
        sf::Texture FW190Texture;
        sf::Texture* bulletTexture;
        bool hitted;
        const bool canAttack();
        virtual void update();
        virtual void render(sf::RenderTarget& target);
        virtual void initVariables();
        virtual void initSprite();
        std::vector<Bullet*>& enemyBullets;
        sf::Clock clock;
};

#endif // FW190_H
