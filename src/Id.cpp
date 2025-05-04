#pragma once

#include "Id.h"

Id::Id(int& yOffset)
    :InputInt(yOffset, "Id:") {
}

//=========================================
bool Id::validateInput(){

	if (m_input.size() < 5 || m_input.size() > 9)
		return false;

    int x = m_input.size() - 9;
    int sum = 0;
    m_input.insert(m_input.begin(), std::abs(x), 0);

	for (int i = 0; i < m_input.size(); i++)
	{
		int mult = (i % 2 == 0) ? 1 : 2;
		int prod = m_input[i] * mult;
		if (prod > 9) {
			sum += prod / 10;
			sum += prod % 10;
		}
		else
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

    Input::drawToPresent(window, yOffset);
}
