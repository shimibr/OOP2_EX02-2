#pragma once
#include "FieldToInput.h"
#include "InputChar.h"

class Address : public InputChar
{
public:
	Address(int& yOffset, std::string fieldName);
	bool drawToPresent(sf::RenderWindow& window, int& yOffset)override;

private:
	bool validateHelper(int i, int &j);
	bool validateInput();

};
