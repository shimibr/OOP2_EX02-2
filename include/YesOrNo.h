#pragma once
#include "FieldToInput.h"


class YesOrNo : public FieldToInput
{
public:
	YesOrNo(int& yOffset, std::string fieldName);
	bool validateInput();
	void drawToPresent(sf::RenderWindow& window, int& yOffset)override;

private:

};
