#pragma once

#include "Name.h"

Name::Name(int& yOffset)
	:FieldToInput(yOffset, "Name:") { }

//=========================================
bool Name::validateInput(sf::RenderWindow& window, int& yOffset)
{
    for (char ch : m_inputString)
    {
       if (std::isdigit(static_cast<unsigned char>(ch)))
       {
           m_PresentError.setString("The input does not adhere to the expected format");
           m_PresentError.setPosition(50 , yOffset += 30);
           window.draw(m_PresentError);
           return false;
       }

    }
    return true;
}
//=========================================
void Name::drawToPresent(sf::RenderWindow& window, int& yOffset)
{
	FieldToInput::drawToPresent(window, yOffset);
	if (!validateInput(window, yOffset))
	{
	}
}
