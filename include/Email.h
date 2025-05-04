#pragma once
#include "FieldToInput.h"
#include "InputChar.h"

class Email : public InputChar
{
public:
	Email(int& yOffset);
	bool validateInput();
	void drawToPresent(sf::RenderWindow& window, int& yOffset)override;

private:
	bool isValidChar(char c) const;

};
