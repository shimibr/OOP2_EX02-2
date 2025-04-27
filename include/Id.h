#pragma once
#include "FieldToInput.h"


class Id : public FieldToInput
{
public:
	Id(int& yOffset);
	bool validateInput();
	void drawToPresent(sf::RenderWindow& window, int& yOffset)override;

private:

};
