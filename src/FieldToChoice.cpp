#include "FieldToChoice.h"


FieldToChoice::FieldToChoice(std::string name, const int sizeText, sf::Vector2f size, sf::Vector2f position, sf::Color ColorRec,
	sf::Color ColorText, std::string text, std::vector< std::pair<std::string, bool>> selectOptions)
	: RectangleToFill(name,sizeText,size,position,ColorRec,ColorText,text)
{
	for (int i = 0; i < selectOptions.size(); i++)
	{
		m_selectOptions.push_back(RectanglText(sizeText, sf::Vector2f(600 / selectOptions.size(), 40), sf::Vector2f(20 + 600 / selectOptions.size() * i, position.y + 50)
			, selectOptions[i].second ? sf::Color(0, 120, 255) : sf::Color::White
			, (selectOptions[i].second ? sf::Color::White : sf::Color::Black), selectOptions[i].first));
	}
}
//=======================================
void FieldToChoice::drawRec(sf::RenderWindow& Window)
{
	RectangleToFill::drawRec(Window);
	for (int i = 0; i < m_selectOptions.size(); i++)
	{
		m_selectOptions[i].drawRec(Window);
	}
}
