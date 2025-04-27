#pragma once
#include "FieldToInput.h"


class Name : public FieldToInput
{
public:
	Name(int &yOffset);
	bool validateInput() ;
	void drawToPresent(sf::RenderWindow& window, int& yOffset)override ;

private:

};
