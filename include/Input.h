#pragma once
#include "FieldToInput.h"

// Template class definition
template<typename T>
class Input : public FieldToInput
{
public:
    Input(int& yOffset, std::string nameBox);
	void setInput(T input) {m_input.push_back(input); }
	void setInputBack() override;
	void drawToForm(sf::RenderWindow& window)  override;
protected:
	char toString(int vale) { return char(vale + '0'); }
	char toString(char vale) { return vale; }
    std::vector<T> m_input; 
};
//=========================================
template<typename T>
inline Input<T>::Input(int& yOffset, std::string nameBox)
	: FieldToInput(yOffset, nameBox)
{ }
//=========================================
template<typename T>
inline void Input<T>::setInputBack()
{
	if (!m_input.empty())
		m_input.pop_back();
}
//========================================
template<typename T>
inline void Input<T>::drawToForm(sf::RenderWindow& window)
{
	
	static sf::Clock cursorTimer;
	bool cursorVisible = (cursorTimer.getElapsedTime().asMilliseconds() % 1000 < 500);
	m_inputBox.setOutlineColor(m_isSelected ? sf::Color(0, 120, 255) : sf::Color(160, 160, 160));

	std::string inputString;
	for (const T item : m_input)
	{
		inputString +=toString(item); // Convert each item to string and add a space
	}

	m_inputText.setString(inputString);// +(m_isSelected && cursorVisible ? "|" : ""));
	window.draw(m_inputBox);
	window.draw(m_inputText);
	window.draw(m_nameBox);

}

