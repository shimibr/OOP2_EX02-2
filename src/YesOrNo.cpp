#pragma once

#include "YesOrNo.h"

YesOrNo::YesOrNo(int& yOffset, std::string fieldName)
    :InputChar(yOffset, fieldName) {
}

//=========================================
bool YesOrNo::validateInput()
{
    if (isYes() || isNo())
    {
        return true;
    }
	return false;
}
//=========================================
bool YesOrNo::drawToPresent(sf::RenderWindow& window, int& yOffset)
{
    if (!validateInput())
        m_errorString = "The input does not adhere to the expected format";
    else
        m_errorString = "";

    return Input::drawToPresent(window, yOffset);

}
//=========================================
bool YesOrNo::isYes() const
{
        return (m_input.size() == 3 && m_input[0] == 'y' || m_input[0] == 'Y') && (m_input[1] == 'e' || m_input[1] == 'E') && (m_input[2] == 's' || m_input[2] == 'S');
}

bool YesOrNo::isNo() const
{
	return (m_input.size() == 2 && m_input[0] == 'n' || m_input[0] == 'N') && (m_input[1] == 'o' || m_input[1] == 'O');
}
