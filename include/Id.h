#pragma once
#include "FieldToInput.h"


class Id : public FieldToInput
{
public:
	Id(int& yOffset);
	bool validateInput(sf::RenderWindow& window, int& yOffset);
	void drawToPresent(sf::RenderWindow& window, int& yOffset)override;

private:

};
