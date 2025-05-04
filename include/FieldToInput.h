
#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <any>

class Gps;
class CarType;
class ChildSeat;

class FieldToInput
{
public:
	FieldToInput(int& yOffset, std::string nameBox);
	virtual ~FieldToInput() = default; // Add a virtual destructor 
	virtual void setInput(int input) {}
	virtual void setInput(char input) { //במחלקה שבו הוא צריך לקבל INT
		if (input >= '0' && input <= '9') 
		setInput(int(input -= '0'));
	}
	virtual void setInputBack() = 0;
	virtual void setIsSelected(bool isSelected) = 0;
	virtual bool isInputBox(sf::Vector2f mousePos) = 0;
	virtual void drawToForm(sf::RenderWindow& window) = 0;
	virtual bool drawToPresent(sf::RenderWindow& window, int& yOffset) = 0;
	virtual bool fieldIsFill()const = 0;
	virtual void printToTerminal() const = 0;

	virtual bool crossFieldTest(const Gps& gps) const { return false; }
	virtual bool crossFieldTest(const CarType& carType) const { return false; }
	virtual bool crossFieldTest(const ChildSeat& childSeat) const { return false; }


protected:
	
	
private:
	

};
