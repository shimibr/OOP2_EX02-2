#pragma once
#include "CarRentalForm.h"
#include "RecPress.h"
#include "InputChar.h"

class FieldToInputSelect : public InputChar
{
public:
	FieldToInputSelect(int& yOffset, std::string nameBox,std::vector<std::string> options,bool multipleSelect,const int dipolat);
	bool isInputBox(sf::Vector2f mousePos) override;
	void drawToForm(sf::RenderWindow& window) override;
	
protected:
	std::vector<RecPress> m_options;

private:
	void fillPressOptions();
	bool m_multipleSelect = false;
};