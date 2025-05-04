#include "InputChar.h"

InputChar::InputChar(int& yOffset, std::string nameBox)
: Input(yOffset, nameBox)
{}

std::string InputChar::inputToString()
{
return std::string(m_input.begin(), m_input.end());
}
