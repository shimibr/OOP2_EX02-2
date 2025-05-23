#pragma once
#include "FieldToInput.h"
#include "InputChar.h"

class YesOrNo : public InputChar
{
public:
	YesOrNo(int& yOffset, std::string fieldName);
	bool drawToPresent(sf::RenderWindow& window, int& yOffset)override;

protected:
	bool isYes() const;
	
private:

	bool isNo() const;
	bool validateInput();
};
