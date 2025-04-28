#pragma once
#include "FieldToInput.h"


class RentTotalDays : public FieldToInput
{
public:
	RentTotalDays(int& yOffset, std::string fieldName);
	bool validateInput();
	void drawToPresent(sf::RenderWindow& window, int& yOffset)override;

private:

};
