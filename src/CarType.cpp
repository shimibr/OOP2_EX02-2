#pragma once
#include "CarType.h"

CarType::CarType(int& yOffset)
	: GustOneSelect(yOffset, "Car Type", std::vector<std::string>{"Economy", "Compact", "Sedan", "SUV", "Luxury"}, 0)
{
}
//=========================================
bool CarType::crossFieldTest(const Gps& gps) const
{
	std::string str(m_input.begin(), m_input.end());
	for (int i = 2; i < m_options.size(); i++)
	{
		if (m_options[i].getText() == str)
			return false;
	}
	return true;
}
