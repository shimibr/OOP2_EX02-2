#pragma once
#include "FieldToInput.h"
#include "InputChar.h"

class Address : public InputChar
{
public:
	Address(int& yOffset, std::string fieldName);
	bool validateInput();
	bool validateHelper(int i, int &j);
	void drawToPresent(sf::RenderWindow& window, int& yOffset)override;

private:

};
