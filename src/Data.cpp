#pragma once

#include "Data.h"

Data::Data(int& yOffset, std::string fieldName)
    :InputChar(yOffset, fieldName) {
	setDefaultValues();
}

//=========================================
bool Data::validateInput()
{
    if (m_input.size() != 10)
        return false;

    if (m_input[4] != '-' || m_input[7] != '-')
        return false;

    for (size_t i = 0; i < m_input.size(); ++i) {
        if (i == 4 || i == 7)
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

    Input::drawToPresent(window, yOffset);
}
//=========================================
void Data::setDefaultValues() 
{
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);  // ✅ Safe alternative to localtime()

    std::string str = std::to_string(1900 + ltm.tm_year) + "-" +
        std::to_string(1 + ltm.tm_mon) + "-" +
        std::to_string(ltm.tm_mday);

	for (char c : str)
		m_input.push_back(c);
}