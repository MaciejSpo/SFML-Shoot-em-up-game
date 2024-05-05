#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <fstream>
class Scoreboard
{
public:
	Scoreboard(sf::RenderWindow* window);
	void draw();
	void readResultsFromFile();
	void updateResultsText();

private:
    float height;
    float width;
	sf::RenderWindow* window;
	sf::Font font;
	sf::Text resultsText;
	sf::Texture scoreboardTexture;
    sf::Sprite scoreboardSprite;
    std::vector<std::string> results;
};

#endif // SCOREBOARD_H
