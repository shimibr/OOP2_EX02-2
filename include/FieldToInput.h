
#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class FieldToInput
{
public:
	FieldToInput(sf::Vector2f position, std::string nameBox);
	void setInput(const char input) {  m_inputString += input ; }
	void setInputBack() { m_inputString.pop_back();}
	bool isInputBox(sf::Vector2f mousePos);

	virtual void drawToForm(sf::RenderWindow& window);
	virtual void drawToPresent(sf::RenderWindow& window, int& yOffset);

protected:
	std::string m_inputString;

private:
	sf::RectangleShape m_inputBox;
	sf::Text m_input;
	sf::Text m_nameBox;
	sf::Text m_Present;
	bool m_isSelected = false;
};