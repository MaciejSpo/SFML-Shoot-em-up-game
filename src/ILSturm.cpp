#include "ILSturm.h"

ILSturm::ILSturm(float pos_x, float pos_y,TextureManager& textureManager,std::vector<Bullet*>& bullets) : Enemy(pos_x,pos_y,textureManager,bullets), enemyBullets(bullets)
{
    this->ILSturmTexture = textureManager.getTexture("ILSturm");
    this->sprite.setTexture(ILSturmTexture);
    this->ILSturmHitted = textureManager.getTexture("ILSturmHitted");
    this->bulletTexture = &textureManager.getTexture("Rocket");
    this->initSprite();
    this->initVariables();
    this->sprite.setPosition(pos_x, pos_y);
    this->pos_x = pos_x;
}

ILSturm::~ILSturm()
{
}


void ILSturm::initVariables()
{
    this->type=4;
    this->attackCooldownMax = 30.0f;
    this->attackCooldown = 40.f;
    this->speed = 0.7f;
    this->reachedMax = false;
    this->hpMax=10;
    this->hp=this->hpMax;
    this->damage=10;
    this->leftShooted = rand()%2;
    this->points=20;
    this->hitted = false;
    this->hitbox1 = sf::FloatRect(0 + this->sprite.getPosition().x , 387*this->sprite.getScale().y + this->sprite.getPosition().y, 972*this->sprite.getScale().x,212*this->sprite.getScale().y);
    this->hitbox2 = sf::FloatRect(452*this->sprite.getScale().x + this->sprite.getPosition().x,194*this->sprite.getScale().y + this->sprite.getPosition().y,72*this->sprite.getScale().x,572*this->sprite.getScale().y);
    this->hitbox3 = sf::FloatRect(320*this->sprite.getScale().x + this->sprite.getPosition().x,27*this->sprite.getScale().y + this->sprite.getPosition().y,332*this->sprite.getScale().x,167*this->sprite.getScale().y);
}

void ILSturm::update()
{
    if(this->hitted) {
        this->clock.restart();
        this->sprite.setTexture(this->ILSturmHitted);
        this->hitted=false;
    }
    if(clock.getElapsedTime() > sf::seconds(0.1f))
        this->sprite.setTexture(this->ILSturmTexture);

    if(this->pos_x <= this->sprite.getPosition().x && !this->reachedMax)
    {
        this->sprite.move(this->speed/3, this->speed *1.3);
        if (this->pos_x +70.f <= this->sprite.getPosition().x )
            this->reachedMax=!this->reachedMax;
    }
    else
    {
        this->sprite.move(this->speed*-1/3,this->speed *1.3);
        if (this->pos_x >= this->sprite.getPosition().x)
            this->reachedMax=!this->reachedMax;
    }
    this->hitbox1 = sf::FloatRect(0 + this->sprite.getPosition().x , 387*this->sprite.getScale().y + this->sprite.getPosition().y, 972*this->sprite.getScale().x,212*this->sprite.getScale().y);
    this->hitbox2 = sf::FloatRect(452*this->sprite.getScale().x + this->sprite.getPosition().x,194*this->sprite.getScale().y + this->sprite.getPosition().y,72*this->sprite.getScale().x,572*this->sprite.getScale().y);
    this->hitbox3 = sf::FloatRect(320*this->sprite.getScale().x + this->sprite.getPosition().x,27*this->sprite.getScale().y + this->sprite.getPosition().y,332*this->sprite.getScale().x,167*this->sprite.getScale().y);
}

void ILSturm::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}

void ILSturm::initSprite()
{
    this -> sprite.scale(0.24f,0.24f);
}
const bool ILSturm::canAttack()
{
    this->attackCooldown+=0.1f;
    if(this->attackCooldown >= this->attackCooldownMax)
    {
        this->attackCooldown = 0.f;
        return true;
    }
    return false;
}
void ILSturm::shoot()
{
        if(this->canAttack()){
            if(this->leftShooted){
                this->enemyBullets.push_back(new Bullet(bulletTexture,
                                           this->getPos().x+this->getBounds().width/3.3,
                                           this->getPos().y+this->getBounds().height/1.6,
                                           0.f,
                                           1.f,
                                           1.8f,
                                           this->damage)
                                );
            }
            else
            {
                this->enemyBullets.push_back(new Bullet(bulletTexture,
                                           this->getPos().x+this->getBounds().width/3*2,
                                           this->getPos().y+this->getBounds().height/1.6,
                                           0.f,
                                           1.f,
                                           1.8f,
                                           this->damage)
                                );
            }
            this->leftShooted = !this->leftShooted;
		}
}
void ILSturm::loseHp(int dmg)
{
    this->hitted = true;
    this->hp -= dmg;
}
