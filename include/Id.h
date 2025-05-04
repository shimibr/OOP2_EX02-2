#pragma once
#include "FieldToInput.h"
#include "InputInt.h"

class Id : public InputInt
{
public:
	Id(int& yOffset);
	bool drawToPresent(sf::RenderWindow& window, int& yOffset)override;

private:
	bool validateInput();

};
