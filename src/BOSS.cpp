#include "BOSS.h"
BOSS::BOSS(float pos_x, float pos_y, TextureManager& textureManager, std::vector<Bullet*>& bullets) : Enemy(pos_x, pos_y, textureManager, bullets), enemyBullets(bullets)
{
    this->bossTexture = textureManager.getTexture("BOSS");
    this->sprite.setTexture(this->bossTexture);
    this->bossHitted = textureManager.getTexture("BOSSHitted");
    this->bulletTexture = &textureManager.getTexture("BOSSBullet");
    this->bulletTexture2 = &textureManager.getTexture("BOSSBullet2");
    this->bulletTexture3 = &textureManager.getTexture("BOSSBullet3");
    this->initVariables();
    this->initSprite();
    this->sprite.setPosition(pos_x, pos_y);
}

BOSS::~BOSS()
{
}


void BOSS::initVariables()
{
    this->type=5;
    this->hitbox1 = sf::FloatRect(213 + this->sprite.getPosition().x, 380 + this->sprite.getPosition().y,200,57);
    this->hitbox2 = sf::FloatRect(274 + this->sprite.getPosition().x,203 + this->sprite.getPosition().y,33,108);
    this->hitbox3 = sf::FloatRect(0 + this->sprite.getPosition().x ,0 + this->sprite.getPosition().y,640,203);
    this->speed = 1.2f;
    this->hpMax=250;
    this->hp=this->hpMax;
    this->damage=5;
    this->points=100;
    this->attackCooldownMax = 20.0f;
    this->attackCooldown = 5.f;
    this->reachedLeft = false;
    this->BulletDirection =0.f;
    this->changeDirection = false;
    this->typeOfShooting = 1;
    this->hitted = false;
    this->maxShootingCounter = 20.f;
    this->shootingCounter = 0.f;
}


void BOSS::update()
{
    if(this->hitted) {
        this->clock.restart();
        this->sprite.setTexture(this->bossHitted);
        this->hitted=false;
    }
    if(clock.getElapsedTime() > sf::seconds(0.1f))
        this->sprite.setTexture(this->bossTexture);

    if(this->sprite.getPosition().y > 50.f){

        if(this->sprite.getPosition().x >= -100.f && !reachedLeft)
        {
            this->sprite.move(-1*this->speed,0.f);
            if(sprite.getPosition().x < -90.f )
            {
                this->reachedLeft = true;
            }
        }
        else
        {
            this->sprite.move(this->speed,0.f);
            if (this->sprite.getPosition().x > 800.f - 500.f)
                this->reachedLeft = false;
        }

    }

    else {
        this->sprite.move(0.f,this->speed);
    }
    this->hitbox1 = sf::FloatRect(213 + this->sprite.getPosition().x, 380 + this->sprite.getPosition().y,200,57);
    this->hitbox2 = sf::FloatRect(274 + this->sprite.getPosition().x,203 + this->sprite.getPosition().y,33,108);
    this->hitbox3 = sf::FloatRect(0 + this->sprite.getPosition().x ,0 + this->sprite.getPosition().y,640,203);
}

void BOSS::initSprite()
{
    this -> sprite.scale(1.1f,1.1f);
}
const bool BOSS::canAttack()
{
    if (this->typeOfShooting == 2)
        this->attackCooldown+=0.1f;

    else this->attackCooldown+=0.8f;

    if(this->attackCooldown >= this->attackCooldownMax)
    {
        this->attackCooldown = 0.f;
        return true;
    }
    return false;
}
void BOSS::shoot()
{
        if(this->canAttack()){
            if (this->shootingCounter>=this->maxShootingCounter)
                {
                    this->typeOfShooting = rand() % 3 + 1;
                    this->shootingCounter=0.f;
                }

            if (this->typeOfShooting == 1)
            {
            if(this->changeDirection)
            {
                this->BulletDirection -=0.05f;
                if(this->BulletDirection<=-0.15f)
                {
                    this->changeDirection = false;
                }
            }
            else
            {
               this->BulletDirection+=0.05f;
                if(this->BulletDirection>=0.15f)
                {
                    this->changeDirection = true;
                }
            }
                enemyBullets.push_back(new Bullet(bulletTexture,
                                                this->getPos().x+this->getBounds().width/2,
                                                this->getPos().y+this->getBounds().height/3,
                                                this->BulletDirection*5,
                                                1.f,
                                                1.9f,
                                                this->damage)
                                );
                this->shootingCounter+=1.0f;
            }

            if (this->typeOfShooting == 2)
            {
                enemyBullets.push_back(new Bullet(bulletTexture2,
                                                this->getPos().x+this->getBounds().width/2,
                                                this->getPos().y+this->getBounds().height/3,
                                                0.6f,
                                                1.f,
                                                1.5f,
                                                this->damage*2)
                                );
                enemyBullets.push_back(new Bullet(bulletTexture2,
                                                this->getPos().x+this->getBounds().width/2,
                                                this->getPos().y+this->getBounds().height/3,
                                                0.f,
                                                1.f,
                                                1.5f,
                                                this->damage*2)
                                );
                enemyBullets.push_back(new Bullet(bulletTexture2,
                                                this->getPos().x+this->getBounds().width/2,
                                                this->getPos().y+this->getBounds().height/3,
                                                -0.6f,
                                                1.f,
                                                1.5f,
                                                this->damage*2)
                                );
                this->shootingCounter+=10.f;
            }
            if (this->typeOfShooting == 3)
            {
                enemyBullets.push_back(new Bullet(bulletTexture3,
                                                this->getPos().x+this->getBounds().width/2,
                                                this->getPos().y+this->getBounds().height/3,
                                                0.9f,
                                                1.f,
                                                1.8f,
                                                this->damage*3)
                                        );
                enemyBullets.push_back(new Bullet(bulletTexture3,
                                                this->getPos().x+this->getBounds().width/2,
                                                this->getPos().y+this->getBounds().height/3,
                                                0.7f,
                                                1.f,
                                                1.8f,
                                                this->damage*3)
                                        );
                enemyBullets.push_back(new Bullet(bulletTexture3,
                                                this->getPos().x+this->getBounds().width/2,
                                                this->getPos().y+this->getBounds().height/3,
                                                0.3f,
                                                1.f,
                                                1.8f,
                                                this->damage*3)
                                        );
                enemyBullets.push_back(new Bullet(bulletTexture3,
                                                this->getPos().x+this->getBounds().width/2,
                                                this->getPos().y+this->getBounds().height/3,
                                                0.0f,
                                                1.f,
                                                1.8f,
                                                this->damage*3)
                                        );
                enemyBullets.push_back(new Bullet(bulletTexture3,
                                                this->getPos().x+this->getBounds().width/2,
                                                this->getPos().y+this->getBounds().height/3,
                                                -0.3f,
                                                1.f,
                                                1.8f,
                                                this->damage*3)
                                       );
                enemyBullets.push_back(new Bullet(bulletTexture3,
                                                this->getPos().x+this->getBounds().width/2,
                                                this->getPos().y+this->getBounds().height/3,
                                                -0.7f,
                                                1.f,
                                                1.8f,
                                                this->damage*3)
                                       );
                enemyBullets.push_back(new Bullet(bulletTexture3,
                                                this->getPos().x+this->getBounds().width/2,
                                                this->getPos().y+this->getBounds().height/3,
                                                -0.9f,
                                                1.f,
                                                1.8f,
                                                this->damage*3)
                                        );
                this->shootingCounter+=20.f;
            }
		}
}
void BOSS::loseHp(int dmg)
{
    this->hitted = true;
    this->hp -= dmg;
}

void BOSS::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}

