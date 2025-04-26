#include "RectanglText.h"

RectanglText::RectanglText(const int sizeText, sf::Vector2f size, sf::Vector2f position, sf::Color ColorRec, sf::Color ColorText
	, std::string text)
{
	m_Rectangle.setSize(size);
	m_Rectangle.setPosition(position);
	m_Rectangle.setFillColor(ColorRec);
	fillText(sizeText, position, ColorText, text);
}
//===========================
RectanglText::RectanglText(const int sizeText, sf::Vector2f position, sf::Color ColorText, std::string text)
{
	m_withRectangle = false;
	fillText(sizeText, position, ColorText, text);
}
//=======================================
void RectanglText::drawRec(sf::RenderWindow& Window)
{
	if (m_withRectangle)
		Window.draw(m_Rectangle);

	Window.draw(m_Text);
}
//=======================================
void RectanglText::setOutline(sf::Color color)
{
	m_Rectangle.setOutlineThickness(2);
	m_Rectangle.setOutlineColor(color);
}
//=======================================
void RectanglText::fillText(const int sizeText, sf::Vector2f position, sf::Color ColorText, std::string text)
{
	static sf::Font font;
	static bool isLoad = false;
	if (!isLoad) {
		font.loadFromFile("C:/Windows/Fonts/arialbd.ttf");
		isLoad = true;
	}
	m_Text.setFont(font);
	m_Text.setString(text);
	m_Text.setCharacterSize(sizeText);
	m_Text.setFillColor(ColorText);
	m_Text.setPosition(position.x + 8, position.y + 10);
}
