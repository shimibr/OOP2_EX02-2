#pragma once
#include "FieldToInput.h"


class Email : public FieldToInput
{
public:
	Email(int& yOffset);
	bool validateInput(sf::RenderWindow& window, int& yOffset);
	void drawToPresent(sf::RenderWindow& window, int& yOffset)override;

private:
	bool isValidChar(char c) const;

};
