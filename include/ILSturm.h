#ifndef ILSTURM_H
#define ILSTURM_H
#include "Enemy.h"
#include "TextureManager.h"
#include "Bullet.h"

class ILSturm : public Enemy
{
    public:
        ILSturm(float pos_x, float pos_y,TextureManager& textureManager,std::vector<Bullet*>& bullets);
        virtual ~ILSturm();
        void shoot();
        void loseHp(int dmg);
    protected:

    private:
        sf::Texture ILSturmTexture;
        sf::Texture ILSturmHitted;
        sf::Texture* bulletTexture;
        sf::Clock clock;
        bool hitted;
        const bool canAttack();
        bool leftShooted;
        bool reachedMax;
        float pos_x;
        virtual void update();
        virtual void render(sf::RenderTarget& target);
        virtual void initVariables();
        virtual void initSprite();
        std::vector<Bullet*>& enemyBullets;
};

#endif // ILSTURM_H
