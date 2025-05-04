#pragma once
#include "FieldToInput.h"
#include "InputChar.h"

class Data : public InputChar
{
public:
	Data(int& yOffset, std::string fieldName);
	bool validateInput();
	void drawToPresent(sf::RenderWindow& window, int& yOffset)override;

private:

};
