#ifndef MITSUZERO_H
#define MITSUZERO_H
#include "Enemy.h"
#include "TextureManager.h"
#include "Bullet.h"


class MitsuZero : public Enemy
{
    public:
        MitsuZero(float pos_x, float pos_y,TextureManager& textureManager,std::vector<Bullet*>& bullets);
        virtual ~MitsuZero();
        void shoot();
        void loseHp(int dmg);
    protected:
        sf::Texture mitsuTexture;
        sf::Texture mitsuHitted;
        sf::Texture* bulletTexture;
        bool hitted;
        const bool canAttack();
        virtual void update();
        virtual void render(sf::RenderTarget& target);
        virtual void initVariables();
        virtual void initSprite();
        std::vector<Bullet*>& enemyBullets;
        sf::Clock clock;

    private:
};

#endif // MITSUZERO_H
