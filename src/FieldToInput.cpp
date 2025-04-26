#include "FieldToInput.h"

FieldToInput::FieldToInput(sf::Vector2f position,std::string nameBox)
{
	m_inputBox.setSize(sf::Vector2f(250, 35));
	m_inputBox.setPosition(position);
	m_inputBox.setFillColor(sf::Color::White);
	m_inputBox.setOutlineThickness(2);

	static sf::Font font;
	static bool isLoad = false;
	if (!isLoad) {
		font.loadFromFile("C:/Windows/Fonts/arialbd.ttf");
		isLoad = true;
	}

	m_input.setFont(font);
	m_input.setCharacterSize(16);
	m_input.setFillColor(sf::Color(60, 60, 60));
	m_input.setPosition(position.x + 5, position.y + 8);

	m_nameBox.setFont(font);
	m_nameBox.setCharacterSize(18);
	m_nameBox.setFillColor(sf::Color(60, 60, 60));
	m_nameBox.setPosition(20, position.y +5);
	m_nameBox.setString(nameBox);

	m_Present.setFont(font);
	m_Present.setCharacterSize(18);
	m_Present.setFillColor(sf::Color::Black);
}
//==========================================
bool FieldToInput::isInputBox(sf::Vector2f mousePos)
{
	if (m_inputBox.getGlobalBounds().contains(mousePos))
		m_isSelected = true;
	else
		m_isSelected = false;

	return m_isSelected;
}
//=======================================
void FieldToInput::drawToForm(sf::RenderWindow& window)
{
	static sf::Clock cursorTimer;
	bool cursorVisible = (cursorTimer.getElapsedTime().asMilliseconds() % 1000 < 500);
	m_inputBox.setOutlineColor(m_isSelected ? sf::Color(0, 120, 255) : sf::Color(160, 160, 160));
	m_input.setString(m_inputString + (m_isSelected && cursorVisible ? "|" : ""));
	window.draw(m_inputBox);
	window.draw(m_input);
	window.draw(m_nameBox);
}
//=======================================
void FieldToInput::drawToPresent(sf::RenderWindow& window, int& yOffset)
{
	std::string displayText = m_nameBox.getString()+" "+ m_inputString;
	m_Present.setString(displayText);
	m_Present.setPosition(30, yOffset);
	window.draw(m_Present);
}
