
#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <any>

class FieldToInput
{
public:
	FieldToInput(int& yOffset, std::string nameBox);
	virtual ~FieldToInput() = default; // Add a virtual destructor  
	virtual void setInput(const int input) {}
	virtual void setInput(char input) {
		if (input >= '0' && input <= '9')
			setInput(int(input-'0'));
	}
	virtual void setInputBack() {};
	void setIsSelected(bool isSelected) { m_isSelected = isSelected; }

	virtual bool isInputBox(sf::Vector2f mousePos);
	virtual void drawToForm(sf::RenderWindow& window);
	virtual void drawToPresent(sf::RenderWindow& window, int& yOffset);
	bool fieldIsFill()const { return m_inputString.size() > 0; }
protected:
	
	std::string m_inputString;
	std::string m_errorString;
	sf::Text m_inputText; //gtfyuhijk
	bool m_isSelected = false; //yguhijhgyguhijkl
	sf::RectangleShape m_inputBox;//dfcghjfcghj
	sf::Text m_nameBox;//gvyuhgvyhu
private:
	void pellFrontText(sf::Text& Text,const int size, sf::Color color);

	sf::Text m_PresentError;
	sf::Text m_Present; 
};
