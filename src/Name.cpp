#pragma once

#include "Name.h"

Name::Name(int& yOffset, std::string name)
	:InputChar(yOffset, name) { }

//=========================================
bool Name::validateInput()
{
    if (m_inputString.empty()) {
        return false;
    }

    for (char ch : m_inputString)
    {
       if (std::isdigit(static_cast<unsigned char>(ch)))
       {
           return false;
       }

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
