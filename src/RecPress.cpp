#include "RecPress.h"

RecPress::RecPress(sf::Vector2f position, sf::Vector2f size, std::string name,sf::Color color)
{
	m_rec.setSize(size);
	m_rec.setPosition(position);
	m_rec.setFillColor(color);

	static sf::Font font;
	static bool isLoad = false;
	if (!isLoad) {
		font.loadFromFile("C:/Windows/Fonts/arialbd.ttf");
		isLoad = true;
	}
	m_possibility.setFont(font);
	m_possibility.setCharacterSize(16);
	m_possibility.setFillColor(sf::Color(60, 60, 60));
	m_possibility.setPosition(position.x + 5, position.y + 8);
	m_possibility.setString(name);

}
//=========================================
void RecPress::setColor()
{
	m_rec.setFillColor(m_isSelected ? sf::Color(0, 120, 255) : sf::Color::White);
	m_possibility.setFillColor(m_isSelected ? sf::Color::White : sf::Color(60, 60, 60));
}
//=========================================
void RecPress::setOutline(sf::Color color)
{
	m_rec.setOutlineThickness(2);
	m_rec.setOutlineColor(color);
}
//=========================================
std::string RecPress::getPossibility() const
{
	if (m_isSelected)
		return m_possibility.getString();

	return "";
}
//=========================================
void RecPress::drawRec(sf::RenderWindow& window)
{
	window.draw(m_rec);
	window.draw(m_possibility);
}
//=========================================
bool RecPress::isRecPress(sf::Vector2f mousePos)
{
	
	if (m_rec.getGlobalBounds().contains(mousePos))
	{
		m_isSelected = !m_isSelected;
	//	m_rec.setFillColor(m_isSelected ? sf::Color(0, 120, 255) : sf::Color::White);
		//m_possibility.setFillColor(m_isSelected ? sf::Color::White : sf::Color(60, 60, 60));
		return true;
	}
	return false;
	
	
}
