#pragma once
#include "FieldToInput.h"
#include "Input.h"

class Between : public Input<char>
{
public:
	Between(int& yOffset, std::string fieldName);
	bool validateInput();
	void drawToPresent(sf::RenderWindow& window, int& yOffset)override;

private:

};
