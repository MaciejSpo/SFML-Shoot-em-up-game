#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
class Player
{
    public:
        Player();
        virtual ~Player();
        //Accessor
        const sf::Vector2f& getPos() const;
        const sf::FloatRect getBounds() const;
        const int& getHP() const;
        const int& getHPMax() const;
        //Functions
        const bool canAttack();
        void move(const float dirX,const float dirY);
        void update();
        void updateAttack();
        void render(sf::RenderTarget& target);
        //Modifiers
        void setPosition(const sf::Vector2f pos);
        void setPosition(const float x, const float y);
        void setHp(const int hp);
        void loseHp(const int value);
        sf::Sprite sprite;
        sf::FloatRect hitbox1;
        sf::FloatRect hitbox2;
        sf::FloatRect hitbox3;
        sf::Texture texture;
        sf::Texture textureD;
        sf::Texture textureDM;
        sf::Texture textureA;
        sf::Texture textureAM;
        sf::Clock clock;
        bool wasAKeyPressed = false;
        bool wasDKeyPressed = false;
        void initVariables();
        int getDamage();
    protected:

    private:

        float movementSpeed;
        float attackCooldown;
        float attackCooldownMax;
        int hp;
        int hpMax;
        int damage;

        void initTexture();
        void initSprite();
        //void initVariables();



};

#endif // PLAYER_H
