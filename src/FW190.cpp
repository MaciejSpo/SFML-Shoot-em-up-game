#include "FW190.h"

FW190::FW190(float pos_x, float pos_y,TextureManager& textureManager,std::vector<Bullet*>& bullets) : Enemy(pos_x,pos_y,textureManager,bullets), enemyBullets(bullets)
{
    this->FW190Hitted = textureManager.getTexture("FW190Hitted");
    this->FW190Texture = textureManager.getTexture("FW190");
    this->sprite.setTexture(textureManager.getTexture("FW190"));
    this->bulletTexture = &textureManager.getTexture("BULLETtyp2");
    this->initSprite();
    this->initVariables();
    this->sprite.setPosition(pos_x, pos_y);
}

FW190::~FW190()
{
}


void FW190::initVariables()
{
    this->type=3;
    this->attackCooldownMax = 34.0f;
    this->attackCooldown = 20.f;
    this->speed = 1.4f;
    this->hpMax=3;
    this->hp=this->hpMax;
    this->damage=5;
    this->points=12;
    this->hitted=false;
    this->hitbox1 = sf::FloatRect(0 + this->sprite.getPosition().x , 403*this->sprite.getScale().y + this->sprite.getPosition().y, 843*this->sprite.getScale().x,170*this->sprite.getScale().y);
    this->hitbox2 = sf::FloatRect(368*this->sprite.getScale().x + this->sprite.getPosition().x,105*this->sprite.getScale().y + this->sprite.getPosition().y,104*this->sprite.getScale().x,601*this->sprite.getScale().y);
    this->hitbox3 = sf::FloatRect(269*this->sprite.getScale().x + this->sprite.getPosition().x,22*this->sprite.getScale().y + this->sprite.getPosition().y,303*this->sprite.getScale().x,84*this->sprite.getScale().y);
}

void FW190::update()
{
    if(this->hitted) {
        this->clock.restart();
        this->sprite.setTexture(this->FW190Hitted);
        this->hitted=false;
    }
    if(clock.getElapsedTime() > sf::seconds(0.1f))
        this->sprite.setTexture(this->FW190Texture);
    this->sprite.move(0.f,this->speed);
    this->hitbox1 = sf::FloatRect(0 + this->sprite.getPosition().x , 403*this->sprite.getScale().y + this->sprite.getPosition().y, 843*this->sprite.getScale().x,170*this->sprite.getScale().y);
    this->hitbox2 = sf::FloatRect(368*this->sprite.getScale().x + this->sprite.getPosition().x,105*this->sprite.getScale().y + this->sprite.getPosition().y,104*this->sprite.getScale().x,601*this->sprite.getScale().y);
    this->hitbox3 = sf::FloatRect(269*this->sprite.getScale().x + this->sprite.getPosition().x,22*this->sprite.getScale().y + this->sprite.getPosition().y,303*this->sprite.getScale().x,84*this->sprite.getScale().y);
}

void FW190::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}

void FW190::initSprite()
{
    this -> sprite.scale(0.15f,0.15f);
}

const bool FW190::canAttack()
{
    this->attackCooldown+=0.1f;
    if(this->attackCooldown >= this->attackCooldownMax)
    {
        this->attackCooldown = 0.f;
        return true;
    }
    return false;
}

void FW190::shoot()
{
        if(this->canAttack()){
            enemyBullets.push_back(new Bullet(bulletTexture,
                                           this->getPos().x+this->getBounds().width/1.2f,
                                           this->getPos().y+this->getBounds().height/2+30.f,
                                           0.f,
                                           1.f,
                                           2.5f,
                                           this->damage)
                                );
        this->enemyBullets.push_back(new Bullet(bulletTexture,
                                           this->getPos().x+this->getBounds().width*0.09f,
                                           this->getPos().y+this->getBounds().height/2+27.f,
                                           0.f,
                                           1.f,
                                           2.5f,
                                           this->damage)
                                );
		}
}
void FW190::loseHp(int dmg)
{
    this->hitted = true;
    this->hp -= dmg;
}

