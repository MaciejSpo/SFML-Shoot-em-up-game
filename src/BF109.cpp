#include "BF109.h"

BF109::BF109(float pos_x, float pos_y,TextureManager& textureManager,std::vector<Bullet*>& bullets) : Enemy(pos_x,pos_y,textureManager,bullets), enemyBullets(bullets)
{
    this->BF109Texture = textureManager.getTexture("BF109");
    this->sprite.setTexture(BF109Texture);
    this->BF109Hitted = textureManager.getTexture("BF109Hitted");
    this->bulletTexture = &textureManager.getTexture("BULLETtyp1");
    this->initSprite();
    this->initVariables();
    this->sprite.setPosition(pos_x, pos_y);
}

BF109::~BF109()
{
}


void BF109::initVariables()
{
    this->type=2;
    this->attackCooldownMax = 30.0f;
    this->attackCooldown = 30.f;
    this->speed = 1.2f;
    this->hpMax=4;
    this->hp=this->hpMax;
    this->damage=5;
    this->points=15;
    this->hitted = false;
    this->hitbox1 = sf::FloatRect(0 + this->sprite.getPosition().x , 310*this->sprite.getScale().y + this->sprite.getPosition().y, 647*this->sprite.getScale().x,137*this->sprite.getScale().y);
    this->hitbox2 = sf::FloatRect(289*this->sprite.getScale().x + this->sprite.getPosition().x,77*this->sprite.getScale().y + this->sprite.getPosition().y,72*this->sprite.getScale().x,515*this->sprite.getScale().y);
    this->hitbox3 = sf::FloatRect(238*this->sprite.getScale().x + this->sprite.getPosition().x,37*this->sprite.getScale().y + this->sprite.getPosition().y,252*this->sprite.getScale().x,104*this->sprite.getScale().y);
}

void BF109::update()
{
    if(this->hitted) {
        this->clock.restart();
        this->sprite.setTexture(this->BF109Hitted);
        this->hitted=false;
    }
    if(clock.getElapsedTime() > sf::seconds(0.1f))
        this->sprite.setTexture(this->BF109Texture);

    this->sprite.move(0.f,this->speed);
    this->hitbox1 = sf::FloatRect(0 + this->sprite.getPosition().x , 310*this->sprite.getScale().y + this->sprite.getPosition().y, 647*this->sprite.getScale().x,137*this->sprite.getScale().y);
    this->hitbox2 = sf::FloatRect(289*this->sprite.getScale().x + this->sprite.getPosition().x,77*this->sprite.getScale().y + this->sprite.getPosition().y,72*this->sprite.getScale().x,515*this->sprite.getScale().y);
    this->hitbox3 = sf::FloatRect(238*this->sprite.getScale().x + this->sprite.getPosition().x,37*this->sprite.getScale().y + this->sprite.getPosition().y,252*this->sprite.getScale().x,104*this->sprite.getScale().y);
}

void BF109::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}

void BF109::initSprite()
{
    this -> sprite.scale(0.2f,0.2f);
}
const bool BF109::canAttack()
{
    this->attackCooldown+=0.1f;
    if(this->attackCooldown >= this->attackCooldownMax)
    {
        this->attackCooldown = 0.f;
        return true;
    }
    return false;
}
void BF109::shoot()
{
        if(this->canAttack()){
            enemyBullets.push_back(new Bullet(bulletTexture,
                                           this->getPos().x+this->getBounds().width,
                                           this->getPos().y+this->getBounds().height/2,
                                           0.f,
                                           1.f,
                                           1.8f,
                                           this->damage)
                                );
        this->enemyBullets.push_back(new Bullet(bulletTexture,
                                           this->getPos().x,
                                           this->getPos().y+this->getBounds().height/2-2.f,
                                           0.f,
                                           1.f,
                                           1.8f,
                                           this->damage)
                                );
		}
}
void BF109::loseHp(int dmg)
{
    this->hitted = true;
    this->hp -= dmg;
}
