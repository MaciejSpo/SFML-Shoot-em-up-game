#include "Menu.h"
#include <iostream>

Menu::Menu(sf::RenderWindow* window)
{
    this->window = window;
    height = window->getSize().y;
    width = window->getSize().x;
    if (!font.loadFromFile("Fonts/PixellettersFull.ttf"))
	{
	}

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Graj");
	menu[0].setPosition(sf::Vector2f(width / 2 + 200, height / ((MAX_NUMBER_OF_ITEMS + 1) * 2)+150)); //*1

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Wyniki");
	menu[1].setPosition(sf::Vector2f(width / 2 + 200, height / ((MAX_NUMBER_OF_ITEMS + 1) * 3)+275)); //*2

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Koniec");
	menu[2].setPosition(sf::Vector2f(width / 2 + 200, height / ((MAX_NUMBER_OF_ITEMS + 1) * 4)+400)); //*3

	selectedItemIndex = 0;

	if (!backgroundTexture.loadFromFile("Textures/samolot800x1000.png"))
    {
    }

    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, 0);

    textManual.setFont(font);
    textManual.setCharacterSize(25);
    textManual.setFillColor(sf::Color::White);
    textManual.setPosition(sf::Vector2f(width / 2 + 100, (height / 5)-25));
    textManual.setString("Aby wybrac wcisnij Spacje\nAby wyciszyc dzwiek wcisnij M");

    textCredits.setFont(font);
    textCredits.setCharacterSize(25);
    textCredits.setFillColor(sf::Color::Black);
    textCredits.setPosition(sf::Vector2f(width / 2+200, height / 5+450));
    textCredits.setString("Wykonali:\nMaciej Spochacz\nBartosz Studzinski");
}

void Menu::draw()
{
    window->draw(backgroundSprite);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window->draw(menu[i]);
	}
	window->draw(textManual);
	window->draw(textCredits);
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS-1)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}


