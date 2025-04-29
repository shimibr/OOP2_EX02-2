#pragma once
#include "FieldToInput.h"

// Template class definition
template<typename T>
class Input : public FieldToInput
{
public:
    Input(int& yOffset, std::string nameBox);
	void setInput(T input) {
		m_input.push_back(input); }

private:
    std::vector<T> m_input; 
};

template<typename T>
inline Input<T>::Input(int& yOffset, std::string nameBox)
	: FieldToInput(yOffset, nameBox)
{ }

