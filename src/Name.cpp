#pragma once

#include "Name.h"

Name::Name(int& yOffset, std::string name)
	:InputChar(yOffset, name) { }

//=========================================
bool Name::validateInput()
{
	for (int i = 0; i < m_input.size(); i++)
	{
		if (!std::isalpha(m_input[i]))
			return false;
	}
	return true;
}
//=========================================
void Name::drawToPresent(sf::RenderWindow& window, int& yOffset)
{
	if (!validateInput())
        m_errorString = "The input should not contain numbers";

    else
		m_errorString = "";
	
	Input::drawToPresent(window, yOffset);
}
