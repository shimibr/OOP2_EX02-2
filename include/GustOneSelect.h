#pragma once
#include "FieldToInputSelect.h"


class GustOneSelect : public FieldToInputSelect
{
public:
	GustOneSelect(int& yOffset, std::string fieldName, std::vector<std::string> options, bool multipleSelect, const int dipolat);
	bool validateInput();
	void drawToPresent(sf::RenderWindow& window, int& yOffset)override;

private:

};
