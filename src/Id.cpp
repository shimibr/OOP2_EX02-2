#pragma once

#include "Id.h"

Id::Id(int& yOffset)
    :InputInt(yOffset, "Id:") {
}

//=========================================
bool Id::validateInput(){
    if (m_inputString.length() < 5 || m_inputString.length() > 9) {
        return false;
    }

    std::string paddedID = std::string(9 - m_inputString.length(), '0') + m_inputString;

    int sum = 0;
    for (size_t i = 0; i < paddedID.length(); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(paddedID[i]))) {
            return false; 
        }

        int digit = paddedID[i] - '0';
        int mult = (i % 2 == 0) ? 1 : 2;
        int prod = digit * mult;

        if (prod > 9) {
            prod -= 9;
        }
        sum += prod;
    }
    return (sum % 10 == 0);
}

//=========================================
void Id::drawToPresent(sf::RenderWindow& window, int& yOffset)
{
    if (!validateInput())
		m_errorString = "Wrong control digit";
    else
       m_errorString = "";

    FieldToInput::drawToPresent(window, yOffset);
}
