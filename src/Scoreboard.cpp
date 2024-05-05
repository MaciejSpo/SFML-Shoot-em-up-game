#include "Scoreboard.h"

Scoreboard::Scoreboard(sf::RenderWindow* window)
{
    this->window = window;
    height = window->getSize().y;
    width = window->getSize().x;
    if (!font.loadFromFile("Fonts/PixellettersFull.ttf"))
	{
	}
	resultsText.setFont(font);
    resultsText.setCharacterSize(30);
    resultsText.setFillColor(sf::Color::White);
    resultsText.setPosition(10, 10);

    readResultsFromFile();
    updateResultsText();

    if (!scoreboardTexture.loadFromFile("Textures/scoreboardbackground.png"))
    {
    }

    scoreboardSprite.setTexture(scoreboardTexture);
    scoreboardSprite.setPosition(0, 0);
}

void Scoreboard::readResultsFromFile()
{
    std::ifstream file("wyniki.txt");
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            results.push_back(line);
        }
        file.close();
    }
}

void Scoreboard::updateResultsText()
{
    std::string resultsStr;
    resultsStr = "Gracz oraz jego punktacja\n";
    resultsStr+= "----------------------------------\n";
    for (const auto& result : results)
    {
        resultsStr += result + "\n";
    }
    resultsStr += "\nNacisnij klawisz Backspace aby powrocic do Menu";
    resultsText.setString(resultsStr);
}

void Scoreboard::draw()
{
    window->draw(scoreboardSprite);
    window->draw(resultsText);
}

