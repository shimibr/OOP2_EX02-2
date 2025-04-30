#include "FieldToInput.h"

FieldToInput::FieldToInput(int& yOffset,std::string nameBox)
{
	m_inputBox.setSize(sf::Vector2f(350, 35));
	m_inputBox.setPosition(sf::Vector2f(250, yOffset));
	m_inputBox.setFillColor(sf::Color::White);
	m_inputBox.setOutlineThickness(2);

	
	pellFrontText(m_inputText, 16, sf::Color(60, 60, 60));
	m_inputText.setPosition(255, yOffset + 8);

	pellFrontText(m_nameBox, 18, sf::Color(60, 60, 60));
	m_nameBox.setPosition(20, yOffset +5);
	m_nameBox.setString(nameBox);

	pellFrontText(m_Present, 18, sf::Color::Black);

	pellFrontText(m_PresentError, 16, sf::Color::Red);
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
	m_inputText.setString(m_inputString + (m_isSelected && cursorVisible ? "|" : ""));
	window.draw(m_inputBox);
	window.draw(m_inputText);
	window.draw(m_nameBox);
}
//=======================================
void FieldToInput::drawToPresent(sf::RenderWindow& window, int& yOffset)
{
	std::string displayText = m_nameBox.getString()+" "+ m_inputString;
	m_Present.setString(displayText);
	m_Present.setPosition(30, yOffset);
	window.draw(m_Present);
	if (m_errorString != "")
	{
		m_PresentError.setString(m_errorString);
		m_PresentError.setPosition(50, yOffset += 20);
		window.draw(m_PresentError);
	}
}

//=======================================
void FieldToInput::pellFrontText(sf::Text& Text, const int size, sf::Color color)
{
	static sf::Font font;
	static bool isLoad = false;
	if (!isLoad) {
		font.loadFromFile("C:/Windows/Fonts/arialbd.ttf");
		isLoad = true;
	}

	Text.setFont(font);
	Text.setCharacterSize(size);
	Text.setFillColor(color);
	
}