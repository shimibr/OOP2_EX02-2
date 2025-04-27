#pragma once
#include "FieldToInput.h"


class Address : public FieldToInput
{
public:
	Address(int& yOffset);
	bool validateInput(sf::RenderWindow& window, int& yOffset);
	void drawToPresent(sf::RenderWindow& window, int& yOffset)override;

private:

};
