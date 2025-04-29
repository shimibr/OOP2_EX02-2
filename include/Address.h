#pragma once
#include "FieldToInput.h"
#include "Input.h"

class Address : public Input<char>
{
public:
	Address(int& yOffset, std::string fieldName);
	bool validateInput();
	void drawToPresent(sf::RenderWindow& window, int& yOffset)override;

private:

};
