#pragma once
#include "FieldToInput.h"
#include "Input.h"

class Data : public Input<char>
{
public:
	Data(int& yOffset, std::string fieldName);
	bool validateInput();
	void drawToPresent(sf::RenderWindow& window, int& yOffset)override;

private:

};
