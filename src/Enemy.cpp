#include "Enemy.h"

Enemy::Enemy(float pos_x,float pos_y,TextureManager& textureManager,std::vector<Bullet*>& bullets)
{

}
Enemy::~Enemy()
{

}
//Accessors
const sf::FloatRect Enemy :: getBounds() const
{
    return this->sprite.getGlobalBounds();
}
const sf::Vector2f& Enemy::getPos() const{
    return this -> sprite.getPosition();
}
const int& Enemy :: getPoints() const
{
    return this->points;
}
const int& Enemy::getDamage() const
{
    return this->damage;
}

//Functions
void Enemy ::shoot()
{

}
void Enemy::initVariables()
{

}
void Enemy::initSprite()
{

}
void Enemy::update()
{
}
void Enemy::render(sf::RenderTarget* target)
{
    target->draw(this->sprite);
}
const bool Enemy::canAttack()
{

}
void Enemy::loseHp(int dmg)
{

}
