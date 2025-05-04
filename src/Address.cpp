#pragma once

#include "Address.h"

Address::Address(int& yOffset, std::string fieldName)
    :InputChar(yOffset, fieldName) {
}

//=========================================
bool Address::validateInput()
{
	int j = 1;
    for (int i = 0; i < m_input.size(); i++)
    {
        if (m_input[i] == ' ')
            return false;

		if (m_input[i] == '-')
        {
			if (i == 0 || i == m_input.size() - 1)
				return false;
            j++;
        }
        else if(!validateHelper(i, j) && j != 1)
		{
			return false;
		}
    }
    if (j == 3)
    {
        return true;
    }
    return false;
}
//=========================================
bool Address::validateHelper(int i, int& j)
{
    switch (j%2)
    {
	case 0:
        if (!std::isdigit(m_input[i]))
			return 0;
		break;
	case 1:
        if (!std::isalpha(m_input[i]))
			return 0;
		break;
    default:
        break;
    }
}
//=========================================
void Address::drawToPresent(sf::RenderWindow& window, int& yOffset)
{
    if (!validateInput())
        m_errorString = "The input does not adhere to the expected format";
    else
        m_errorString = "";
   
    Input::drawToPresent(window, yOffset);
        
}
