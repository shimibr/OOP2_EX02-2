#pragma once
#include "FieldToInput.h"
#include "Input.h"

class YesOrNo : public Input<char>
{
public:
	YesOrNo(int& yOffset, std::string fieldName);
	bool validateInput();
	void drawToPresent(sf::RenderWindow& window, int& yOffset)override;

private:

};
