#include "InputInt.h"

InputInt::InputInt(int& yOffset, std::string nameBox)
	:Input(yOffset,nameBox)
{
}
//=======================================
std::string InputInt::inputToString()
{
	std::string inputString;
	for (int i = 0;i < m_input.size();i++)
	{
		inputString += std::to_string(m_input[i]); // Convert each item to string and add a space
	}
	return inputString;
}
//===================================

