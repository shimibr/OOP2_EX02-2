#include "FieldToInputSelect.h"

FieldToInputSelect::FieldToInputSelect(int& yOffset, std::string nameBox, std::vector<std::string> options,bool multipleSelect)
	: FieldToInput(yOffset, nameBox), m_multipleSelect(multipleSelect)
{
	yOffset += 50;
	for (std::size_t i = 0; i < options.size(); ++i) {
		m_options.push_back(RecPress(sf::Vector2f(20 + (500 / options.size()) * i, yOffset), sf::Vector2f(500/options.size() - 10, 30), options[i],sf::Color::White));
		m_options[i].setOutline(sf::Color(160, 160, 160));
	}

}
//=========================================
bool FieldToInputSelect::isInputBox(sf::Vector2f mousePos)
{
	if(FieldToInput::isInputBox(mousePos))
		return true;
	
	for (std::size_t i = 0; i < m_options.size(); ++i)
	{
		if (m_options[i].isRecPress(mousePos))
		{
			if (!m_multipleSelect)
			{
				for (std::size_t j = 0; j < m_options.size(); ++j)
				{
					if (j != i)
						m_options[j].setIsSelected(false);
					m_options[j].setColor();
				}
				m_inputString = m_options[i].getPossibility();
				return true;
			}
			m_inputString = "";
			for (std::size_t i = 0; i < m_options.size(); ++i)
			{
				m_options[i].setColor();
				m_inputString += m_options[i].getPossibility();
			}
			return true;
		}
	}
	return false;
}
//=========================================
void FieldToInputSelect::drawToForm(sf::RenderWindow& window)
{
	for (std::size_t i = 0; i < m_options.size(); ++i) 
		m_options[i].drawRec(window);
	
	FieldToInput::drawToForm(window);
}
//=========================================
void FieldToInputSelect::drawToPresent(sf::RenderWindow& window, int& yOffset)
{
	FieldToInput::drawToPresent(window, yOffset);
}
