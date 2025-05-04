#pragma once
#include "Input.h"

class InputChar : public Input<char>
{
public:
	InputChar(int& yOffset, std::string nameBox);
	std::string inputToString() override;
	//virtual void drawToPresent(sf::RenderWindow& window, int& yOffset){}
private:

};