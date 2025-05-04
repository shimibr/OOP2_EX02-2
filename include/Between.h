#pragma once
#include "FieldToInput.h"
#include "InputChar.h"

class Between : public InputChar
{
public:
	Between(int& yOffset, std::string fieldName);
	bool validateInput();
	void drawToPresent(sf::RenderWindow& window, int& yOffset)override;

private:

};
