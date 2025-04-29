#pragma once
#include "FieldToInput.h"
#include "Input.h"

class RentTotalDays : public Input<char>
{
public:
	RentTotalDays(int& yOffset, std::string fieldName);
	bool validateInput();
	void drawToPresent(sf::RenderWindow& window, int& yOffset)override;

private:

};
