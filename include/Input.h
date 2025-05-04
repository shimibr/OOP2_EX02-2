#pragma once
#include "FieldToInput.h"

// Template class definition
template<typename T>
class Input : public FieldToInput
{
public:
    Input(int& yOffset, std::string nameBox);
	void setInput(T input) override {m_input.push_back(input); }
	void setInputBack() override;
	void drawToForm(sf::RenderWindow& window)  override;
	bool fieldIsFill()const override { return m_input.size() > 0; }
	virtual void drawToPresent(sf::RenderWindow& window, int& yOffset);
protected:
	virtual std::string inputToString() { return "0"; }
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

	m_inputText.setString(inputToString() +(m_isSelected && cursorVisible ? "|" : ""));
	window.draw(m_inputBox);
	window.draw(m_inputText);
	window.draw(m_nameBox);

}
//============================================
template<typename T>
inline void Input<T>::drawToPresent(sf::RenderWindow& window, int& yOffset)
{
	std::string displayText = m_nameBox.getString() + " " + inputToString();
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

