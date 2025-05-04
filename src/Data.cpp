#pragma once

#include "Data.h"

Data::Data(int& yOffset, std::string fieldName)
    :InputChar(yOffset, fieldName) {
}

//=========================================
bool Data::validateInput()
{
    if (m_input.size() != 10)
        return false;

    if (m_input[2] != '-' || m_input[5] != '-')
        return false;

    for (size_t i = 0; i < m_input.size(); ++i) {
        if (i == 2 || i == 5)
            continue; 

        if (!std::isdigit(m_input[i]))
            return false;
    }

    return true;
}
//=========================================
bool Data::drawToPresent(sf::RenderWindow& window, int& yOffset)
{
    if (!validateInput())
        m_errorString = "The input does not adhere to the expected format";
    else
        m_errorString = "";

    return Input::drawToPresent(window, yOffset);

}
