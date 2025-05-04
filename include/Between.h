#pragma once
#include "FieldToInput.h"
#include "InputInt.h"

class Between : public InputInt
{
public:
	Between(int& yOffset, std::string fieldName, int min, int max);
	bool validateInput();
	void drawToPresent(sf::RenderWindow& window, int& yOffset)override;

private:
	int m_min;
	int m_max;
};
