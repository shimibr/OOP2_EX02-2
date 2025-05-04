#pragma once

#include "SeatingPreference.h"

SeatingPreference::SeatingPreference(int& yOffset)
	: GustOneSelect(yOffset, "Seating Preference", std::vector<std::string>{ "General Admission", "Front Row", "VIP Section", "Aisle Seat" }, 0)
{
}
//=========================================
bool SeatingPreference::crossFieldTest(const Wheelchair& wheelchair) const
{
	std::string str(m_input.begin(), m_input.end());
	for (int i = 1; i < m_options.size(); i++)
	{
		if (m_options[i].getText() == str)
			return false;
	}
	return true;
}
