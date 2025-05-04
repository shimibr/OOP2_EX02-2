#include "FieldToInputSelect.h"

FieldToInputSelect::FieldToInputSelect(int& yOffset, std::string nameBox, std::vector<std::string> options,bool multipleSelect, const int dipolat)
	: InputChar(yOffset, nameBox), m_multipleSelect(multipleSelect)
{
	yOffset += 50;
	for (std::size_t i = 0; i < options.size(); ++i) {
		m_options.push_back(RecPress(sf::Vector2f(20 + ((500-20) / (options.size()-1)) * i, yOffset), sf::Vector2f(500/(options.size()-1) - 20, 30), options[i],sf::Color::White));
		m_options[i].setOutline(sf::Color(160, 160, 160));
	}
	m_options[dipolat].setIsSelected(true);
	fillPressOptions();

}
//=========================================
bool FieldToInputSelect::isInputBox(sf::Vector2f mousePos)
{
	if(Input::isInputBox(mousePos))
		return true;
	
	for (std::size_t i = 0; i < m_options.size(); ++i)
	{
		if (m_options[i].isRecPress(mousePos))
		{
			if (!m_multipleSelect)
				for (std::size_t j = 0; j < m_options.size(); ++j)
					if (j != i)
						m_options[j].setIsSelected(false);

			fillPressOptions();
			
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
	
	Input::drawToForm(window);
}
//=========================================
void FieldToInputSelect::fillPressOptions()
{
	m_input.clear();
	for (std::size_t i = 0; i < m_options.size(); ++i)
	{
		m_options[i].setColor();
		std::string temp = m_options[i].getPossibility();

		if(!temp.empty() && !m_input.empty())
			m_input.push_back('|');

		for (int i = 0; i < temp.size(); i++)
			m_input.push_back(temp[i]);
		  
	}
}
