#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class RectanglText
{
public:

	RectanglText(const int sizeText, sf::Vector2f size, sf::Vector2f position, sf::Color ColorRec, sf::Color ColorText,std::string text);
	RectanglText(const int sizeText, sf::Vector2f position, sf::Color ColorText, std::string text);
	virtual void drawRec(sf::RenderWindow& Window);
	void setOutline(sf::Color color);
	void setRectangleColor(sf::Color color) { m_Rectangle.setFillColor(color); }

private:
	void fillText(const int sizeText, sf::Vector2f position, sf::Color ColorText, std::string text);

	sf::RectangleShape m_Rectangle;
	sf::Text m_Text;
	bool m_withRectangle = true;
	
};