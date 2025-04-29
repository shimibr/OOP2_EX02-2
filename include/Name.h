#pragma once
#include "FieldToInput.h"
#include "Input.h"


class Name : public Input<char>
{
public:
	Name(int &yOffset, std::string name);
	bool validateInput() ;
	void drawToPresent(sf::RenderWindow& window, int& yOffset)override ;

private:

};
