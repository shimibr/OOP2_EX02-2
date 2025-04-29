#pragma once
#include "FieldToInput.h"
#include "Input.h"

class Email : public Input<char>
{
public:
	Email(int& yOffset);
	bool validateInput();
	void drawToPresent(sf::RenderWindow& window, int& yOffset)override;

private:
	bool isValidChar(char c) const;

};
