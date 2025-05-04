#pragma once

#include "Address.h"

Address::Address(int& yOffset, std::string fieldName)
    :InputChar(yOffset, fieldName) {
}

//=========================================
bool Address::validateInput()
{
    if (m_inputString.find(' ') != std::string::npos) {
        return false;
    }

    size_t firstDash = m_inputString.find('-');
    size_t secondDash = m_inputString.find('-', firstDash + 1);

    if (firstDash == std::string::npos || secondDash == std::string::npos ||
        m_inputString.find('-', secondDash + 1) != std::string::npos) {
        return false;
    }

    std::string street = m_inputString.substr(0, firstDash);
    std::string number = m_inputString.substr(firstDash + 1, secondDash - firstDash - 1);
    std::string city = m_inputString.substr(secondDash + 1);

    if (street.empty()) {
        return false;
    }
    for (char c : street) {
        if (!std::isalpha(static_cast<unsigned char>(c))) {
            return false;
        }
    }

    if (number.empty()) {
        return false;
    }
    for (char c : number) {
        if (!std::isdigit(static_cast<unsigned char>(c))) {
            return false;
        }
    }

    if (city.empty()) {
        return false;
    }
    for (char c : city) {
        if (!std::isalpha(static_cast<unsigned char>(c))) {
            return false;
        }
    }

    return true;
}
//=========================================
void Address::drawToPresent(sf::RenderWindow& window, int& yOffset)
{
    if (!validateInput())
        m_errorString = "The input does not adhere to the expected format";
    else
        m_errorString = "";
   
    FieldToInput::drawToPresent(window, yOffset);
        
}
