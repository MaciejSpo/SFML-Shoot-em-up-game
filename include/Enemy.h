#ifndef ENEMY_H
#define ENEMY_H
#include<SFML/Graphics.hpp>
#include "TextureManager.h"
#include "Bullet.h"
class Enemy
{
    public:
        Enemy(float pos_x,float pos_y,TextureManager& textureManager,std::vector<Bullet*>& bullets);
        virtual ~Enemy();
        //Accessors
        const int& getPoints() const;
        const sf::FloatRect getBounds() const;
        const int& getDamage() const;
        //Functions
        virtual void update();
        virtual void render(sf::RenderTarget* target);
        virtual const bool canAttack();
        const sf::Vector2f& getPos() const;
        virtual void shoot();
        int hp;
        virtual void loseHp(int dmg);
        sf::FloatRect hitbox1;
        sf::FloatRect hitbox2;
        sf::FloatRect hitbox3;
        int type;
    protected:
        float attackCooldown;
        float attackCooldownMax;
        float speed;
        int hpMax;
        int damage;
        int points;
        sf::Sprite sprite;
        virtual void initVariables();
        virtual void initSprite();

};

#endif // ENEMY_H
