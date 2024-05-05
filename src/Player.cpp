#include "Player.h"

void Player::initVariables()
{
    this -> movementSpeed = 3.f;
    this->attackCooldownMax = 10.f;
    this->attackCooldown = this->attackCooldownMax;
    this->hpMax = 100;
    this->hp = this->hpMax;
    this->damage = 1;
    this->setPosition(320,700);
    this->hitbox1 = sf::FloatRect(0 + this->sprite.getPosition().x , 229*this->sprite.getScale().y + this->sprite.getPosition().y, 1389*this->sprite.getScale().x,289*this->sprite.getScale().y);
    this->hitbox2 = sf::FloatRect(614*this->sprite.getScale().x + this->sprite.getPosition().x,0*this->sprite.getScale().y + this->sprite.getPosition().y,163*this->sprite.getScale().x,613*this->sprite.getScale().y);
    this->hitbox3 = sf::FloatRect(408*this->sprite.getScale().x + this->sprite.getPosition().x,905*this->sprite.getScale().y + this->sprite.getPosition().y,585*this->sprite.getScale().x,192*this->sprite.getScale().y);
}

void Player::initTexture()
{
    if(!this -> texture.loadFromFile("Textures/planeM.png"))
    {
        std::cout << "Error" << "\n";
    }
    if(!this -> textureD.loadFromFile("Textures/planeR1.png"))
    {
        std::cout << "Error" << "\n";
    }
        if(!this -> textureA.loadFromFile("Textures/planeLS.png"))
    {
        std::cout << "Error" << "\n";
    }
        if(!this -> textureDM.loadFromFile("Textures/planeR2.png"))
    {
        std::cout << "Error" << "\n";
    }
        if(!this -> textureAM.loadFromFile("Textures/planeLM.png"))
    {
        std::cout << "Error" << "\n";
    }
}

void Player::initSprite()
{
   this -> sprite.setTexture(this -> texture);
   this -> sprite.scale(0.1,0.1);
}

Player::Player()
{
    this->initVariables();
    this -> initTexture();
    this -> initSprite();
}

Player::~Player()
{
    //dtor
}

const sf::Vector2f& Player::getPos() const
{
    return this -> sprite.getPosition();
}

const sf::FloatRect Player :: getBounds() const
{
    return this->sprite.getGlobalBounds();
}

const int& Player :: getHP() const
{
    return this->hp;
}
const int& Player :: getHPMax() const
{
    return this->hpMax;
}

int Player::getDamage()
{
    return this->damage;
}


void Player::setPosition(const sf::Vector2f pos)
{
    this->sprite.setPosition(pos);
}
void Player::setPosition(const float x, const float y)
{
    this->sprite.setPosition(x,y);
}

void Player::setHp(const int hp)
{
    this->hp=hp;
}
void Player :: loseHp(const int value)
{
    this->hp -=value;
    if(this->hp < 0) this->hp=0;
}


void Player::move(const float dirX,const float dirY)
{
    this -> sprite.move(this -> movementSpeed*dirX,this -> movementSpeed*dirY);
}

void Player::update()
{
    this->updateAttack();
}
void Player::updateAttack(){
    if(this->attackCooldown < this->attackCooldownMax){
        this->attackCooldown += 0.5f;
    }
}
const bool Player::canAttack()
{
    if(this->attackCooldown >= this->attackCooldownMax)
    {
        this->attackCooldown = 0.f;
        return true;
    }
    return false;
}

void Player::render(sf::RenderTarget& target)
{
    target.draw(this -> sprite);
    this->hitbox1 = sf::FloatRect(0 + this->sprite.getPosition().x , 229*this->sprite.getScale().y + this->sprite.getPosition().y, 1389*this->sprite.getScale().x,289*this->sprite.getScale().y);
    this->hitbox2 = sf::FloatRect(614*this->sprite.getScale().x + this->sprite.getPosition().x,0*this->sprite.getScale().y + this->sprite.getPosition().y,163*this->sprite.getScale().x,613*this->sprite.getScale().y);
    this->hitbox3 = sf::FloatRect(408*this->sprite.getScale().x + this->sprite.getPosition().x,905*this->sprite.getScale().y + this->sprite.getPosition().y,585*this->sprite.getScale().x,192*this->sprite.getScale().y);
}
