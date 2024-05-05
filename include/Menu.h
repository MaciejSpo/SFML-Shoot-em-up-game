#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#define MAX_NUMBER_OF_ITEMS 4


class Menu
{
public:
	Menu(sf::RenderWindow* window);
	void draw();
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }

private:
    float height;
    float width;
	sf::RenderWindow* window;
    int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Text textManual;
    sf::Text textCredits;

};

#endif // MENU_H
