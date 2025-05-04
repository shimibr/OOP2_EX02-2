#pragma once

#include "Email.h"

Email::Email(int& yOffset)
    :InputChar(yOffset, "Email:") {
}

//=========================================
bool Email::validateInput()
{
	bool isStrudel = false;
    for (int i = 0;i < m_input.size();i++)
    {
		if (m_input[i] == ' ')
			return false;

		if (m_input[i] == '@')
		{
			if (i == 0 || m_input[i+1] == '.')
				return false;
			if (isStrudel)
				return false;

			isStrudel = true;
		}
		if (m_input[i] == '.')
			if (i + 2 >= m_input.size())
					return false;
    }
	return isStrudel;
}
//=========================================
bool Email::drawToPresent(sf::RenderWindow& window, int& yOffset)
{
    if (!validateInput())
		m_errorString = "The input does not adhere to the expected format";
	
    else
        m_errorString = "";

	return Input::drawToPresent(window, yOffset);
}