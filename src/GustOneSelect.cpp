#include "GustOneSelect.h"

GustOneSelect::GustOneSelect(int& yOffset, std::string fieldName, std::vector<std::string> options, bool multipleSelect, const int dipolat)
	: FieldToInputSelect(yOffset, fieldName, options, multipleSelect, dipolat) { }
//=========================================

bool GustOneSelect::validateInput()
{
	for (int i = 0; i < m_options.size(); i++)
	{
		if (m_options[i].getText() == m_inputString)
			return true;
	}
	return false;
}
//=========================================
void GustOneSelect::drawToPresent(sf::RenderWindow& window, int& yOffset)
{
	if (!validateInput())
		m_errorString = "The input does not adhere to the expected format";
	else
		m_errorString = "";
	FieldToInputSelect::drawToPresent(window, yOffset);
}
