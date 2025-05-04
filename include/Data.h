#pragma once
#include "FieldToInput.h"
#include "InputChar.h"

class Data : public InputChar
{
public:
	Data(int& yOffset, std::string fieldName);
	bool drawToPresent(sf::RenderWindow& window, int& yOffset)override;

private:
	bool validateInput();
	void setDefaultValues();

};
