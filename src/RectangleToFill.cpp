#include "RectangleToFill.h"

RectangleToFill::RectangleToFill(std::string name, const int sizeText, sf::Vector2f size, sf::Vector2f position, sf::Color ColorRec, sf::Color ColorText, std::string text)
	:RectanglText(sizeText,size,position, ColorRec, ColorText, text), m_textName(sizeText, sf::Vector2f(20, position.y), ColorText, name)
{
}
//=======================================
void RectangleToFill::drawRec(sf::RenderWindow& Window)
{
	m_textName.drawRec(Window);
	RectanglText::drawRec(Window);
}
