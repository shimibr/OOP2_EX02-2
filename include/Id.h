#pragma once
#include "FieldToInput.h"
#include "Input.h"

class Id : public Input<int>
{
public:
	Id(int& yOffset);
	bool validateInput();
	void drawToPresent(sf::RenderWindow& window, int& yOffset)override;

private:

};
