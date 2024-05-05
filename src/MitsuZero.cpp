#include "MitsuZero.h"

MitsuZero::MitsuZero(float pos_x, float pos_y, TextureManager& textureManager, std::vector<Bullet*>& bullets) : Enemy(pos_x, pos_y, textureManager, bullets), enemyBullets(bullets)
{
    this->mitsuTexture = textureManager.getTexture("Zero");
    this->sprite.setTexture(this->mitsuTexture);
    this->mitsuHitted = textureManager.getTexture("ZeroHitted");
    this->bulletTexture = &textureManager.getTexture("BULLETtyp2");
    this->initVariables();
    this->initSprite();
    this->sprite.setPosition(pos_x, pos_y);
    this->hitted = false;
}

MitsuZero::~MitsuZero()
{
}
void MitsuZero::initVariables()
{
    this->type=1;
    this->speed = 1.2f;
    this->hpMax=5;
    this->hp=this->hpMax;
    this->damage=7;
    this->points=10;
    this->attackCooldownMax = 20.0f;
    this->attackCooldown = 10.f;
    this->hitbox1 = sf::FloatRect(323*this->sprite.getScale().x + this->sprite.getPosition().x,141*this->sprite.getScale().y + this->sprite.getPosition().y,78*this->sprite.getScale().x,461*this->sprite.getScale().y);
    this->hitbox2 = sf::FloatRect(0 + this->sprite.getPosition().x , 278*this->sprite.getScale().y + this->sprite.getPosition().y, 731*this->sprite.getScale().x,164*this->sprite.getScale().y);
    this->hitbox3 = sf::FloatRect(238*this->sprite.getScale().x + this->sprite.getPosition().x,37*this->sprite.getScale().y + this->sprite.getPosition().y,252*this->sprite.getScale().x,104*this->sprite.getScale().y);
}


void MitsuZero::update()
{
    if(this->hitted) {
        this->clock.restart();
        this->sprite.setTexture(this->mitsuHitted);
        this->hitted=false;
    }
    if(clock.getElapsedTime() > sf::seconds(0.1f))
        this->sprite.setTexture(this->mitsuTexture);

    this->sprite.move(0.f,this->speed);
    this->hitbox1 = sf::FloatRect(0 + this->sprite.getPosition().x , 278*this->sprite.getScale().y + this->sprite.getPosition().y, 731*this->sprite.getScale().x,164*this->sprite.getScale().y);
    this->hitbox2 = sf::FloatRect(323*this->sprite.getScale().x + this->sprite.getPosition().x,141*this->sprite.getScale().y + this->sprite.getPosition().y,78*this->sprite.getScale().x,461*this->sprite.getScale().y);
    this->hitbox3 = sf::FloatRect(238*this->sprite.getScale().x + this->sprite.getPosition().x,37*this->sprite.getScale().y + this->sprite.getPosition().y,252*this->sprite.getScale().x,104*this->sprite.getScale().y);
}

void MitsuZero::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}

void MitsuZero::initSprite()
{
    this -> sprite.scale(0.2f,0.2f);
}
const bool MitsuZero::canAttack()
{
    this->attackCooldown+=0.1f;
    if(this->attackCooldown >= this->attackCooldownMax)
    {
        this->attackCooldown = 0.f;
        return true;
    }
    return false;
}
void MitsuZero::shoot()
{
        if(this->canAttack()){
            enemyBullets.push_back(new Bullet(bulletTexture,
                                           this->getPos().x+this->getBounds().width/2-5.f,
                                           this->getPos().y+this->getBounds().height,
                                           0.f,
                                           1.f,
                                           3.0f,
                                           this->damage)
                                );
		}
}
void MitsuZero::loseHp(int dmg)
{
    this->hitted = true;
    this->hp -= dmg;
}

