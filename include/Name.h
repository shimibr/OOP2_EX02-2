#pragma once
#include "FieldToInput.h"
#include "InputChar.h"


class Name : public InputChar
{
public:
	Name(int &yOffset, std::string name);
	bool validateInput() ;
	void drawToPresent(sf::RenderWindow& window, int& yOffset)override ;

private:

};
