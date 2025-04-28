#pragma once
#include "FieldToInput.h"


class Data : public FieldToInput
{
public:
	Data(int& yOffset, std::string fieldName);
	bool validateInput();
	void drawToPresent(sf::RenderWindow& window, int& yOffset)override;

private:

};
