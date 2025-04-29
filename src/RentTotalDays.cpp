#pragma once

#include "RentTotalDays.h"

RentTotalDays::RentTotalDays(int& yOffset, std::string fieldName)
    :Input(yOffset, fieldName) {
}

//=========================================
bool RentTotalDays::validateInput()
{
    if (m_inputString.empty()) {
        return false;
    }

    for (char c : m_inputString) {
        if (!std::isdigit(static_cast<unsigned char>(c))) {
            return false;
        }
    }

    int number = std::stoi(m_inputString);

    return (number >= 1 && number <= 999);
}
//=========================================
void RentTotalDays::drawToPresent(sf::RenderWindow& window, int& yOffset)
{
    if (!validateInput())
        m_errorString = "The input does not adhere to the expected format";
    else
        m_errorString = "";

    FieldToInput::drawToPresent(window, yOffset);

}
