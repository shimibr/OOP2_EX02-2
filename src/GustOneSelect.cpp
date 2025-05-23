#include "GustOneSelect.h"

GustOneSelect::GustOneSelect(int& yOffset, std::string fieldName, std::vector<std::string> options, const int dipolat)
	: FieldToInputSelect(yOffset, fieldName, options, false, dipolat) { }
//=========================================

bool GustOneSelect::validateInput()
{
	std::string str(m_input.begin(), m_input.end());

	for (int i = 0; i < m_options.size(); i++)
	{
		if (m_options[i].getText() == str)
			return true;
	}
	return false;
}
//=========================================
bool GustOneSelect::drawToPresent(sf::RenderWindow& window, int& yOffset)
{
	if (!validateInput())
		m_errorString = "The input does not adhere to the expected format";
	else
		m_errorString = "";
	return Input::drawToPresent(window, yOffset);
}
