#pragma once

#include "Between.h"

Between::Between(int& yOffset, std::string fieldName, int min, int max)
	:InputInt(yOffset, fieldName), m_min(min), m_max(max)
{
}

//=========================================
bool Between::validateInput()
{
    int result = 0;
    for (int digit : m_input) {
        result = result * 10 + digit;
    }
    return result >= m_min && result <= m_max;
}
//=========================================
bool Between::drawToPresent(sf::RenderWindow& window, int& yOffset)
{
    if (!validateInput())
        m_errorString = "The input does not adhere to the expected format";
    else
        m_errorString = "";

    return Input::drawToPresent(window, yOffset);

}
