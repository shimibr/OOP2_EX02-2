#pragma once

#include "Data.h"

Data::Data(int& yOffset, std::string fieldName)
    :InputChar(yOffset, fieldName) {
}

//=========================================
bool Data::validateInput()
{
    if (m_inputString.length() != 10)
        return false;

    if (m_inputString[2] != '-' || m_inputString[5] != '-')
        return false;

    for (size_t i = 0; i < m_inputString.length(); ++i) {
        if (i == 2 || i == 5)
            continue; 

        if (!std::isdigit(static_cast<unsigned char>(m_inputString[i])))
            return false;
    }

    return true;
}
//=========================================
void Data::drawToPresent(sf::RenderWindow& window, int& yOffset)
{
    if (!validateInput())
        m_errorString = "The input does not adhere to the expected format";
    else
        m_errorString = "";

    Input::drawToPresent(window, yOffset);

}
