#pragma once
#include "FieldToInput.h"


class Address : public FieldToInput
{
public:
	Address(int& yOffset);
	bool validateInput();
	void drawToPresent(sf::RenderWindow& window, int& yOffset)override;

private:

};
