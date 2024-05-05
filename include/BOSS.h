#ifndef BOSS_H
#define BOSS_H
#include "Enemy.h"
#include "TextureManager.h"
#include "Bullet.h"
#include <iostream>


class BOSS : public Enemy
{
    public:
        BOSS(float pos_x, float pos_y,TextureManager& textureManager,std::vector<Bullet*>& bullets);
        virtual ~BOSS();
        void shoot();
        void loseHp(int dmg);
    protected:
        sf::FloatRect combinedHitbox;
        bool reachedLeft;
        sf::Texture bossTexture;
        sf::Texture bossHitted;
        sf::Texture* bulletTexture;
        sf::Texture* bulletTexture2;
        sf::Texture* bulletTexture3;
        bool hitted;
        const bool canAttack();
        virtual void update();
        virtual void render(sf::RenderTarget& target);
        virtual void initVariables();
        virtual void initSprite();
        std::vector<Bullet*>& enemyBullets;
        sf::Clock clock;
        float BulletDirection;
        bool changeDirection;
        int typeOfShooting;
        float shootingCounter;
        float maxShootingCounter;
    private:
};

#endif // MITSUZERO_H
