#pragma once

#include "YesOrNo.h"

YesOrNo::YesOrNo(int& yOffset, std::string fieldName)
    :Input(yOffset, fieldName) {
}

//=========================================
bool YesOrNo::validateInput()
{
    return (m_inputString == "Yes" || m_inputString == "No");
}
//=========================================
void YesOrNo::drawToPresent(sf::RenderWindow& window, int& yOffset)
{
    if (!validateInput())
        m_errorString = "The input does not adhere to the expected format";
    else
        m_errorString = "";

    FieldToInput::drawToPresent(window, yOffset);

}
