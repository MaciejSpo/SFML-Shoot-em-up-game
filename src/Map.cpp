#include "Map.h"
Map::Map(sf::Texture* texture, float scale, float movement_speed, int mirrorReflection,sf::RenderWindow* window)
{
    this -> backgroundSprite1.setTexture(*texture);
    this -> backgroundSprite2.setTexture(*texture);
    this -> movementSpeed = movement_speed;
    this -> window = window;
    yWindowPos = window->getSize().y;
    backgroundPosition = backgroundSprite1.getPosition();
    backgroundSprite1.setPosition(0, 0);
    backgroundSprite2.setPosition(0, -yWindowPos);
}

Map::~Map()
{
}


void Map::render(sf::RenderTarget* target)
{
    target -> draw(this->backgroundSprite1);
    target -> draw(this->backgroundSprite2);
}

void Map::update(){
backgroundPosition.y += movementSpeed;

    // Sprawdzenie czy mapa wyszla poza ekran
    if (backgroundPosition.y >= 0)
    {
        backgroundPosition.y -= yWindowPos;
    }


    // Aktualizacja pozycji tla
    backgroundSprite1.setPosition(0, backgroundPosition.y);
    backgroundSprite2.setPosition(0, backgroundPosition.y + yWindowPos);
}
