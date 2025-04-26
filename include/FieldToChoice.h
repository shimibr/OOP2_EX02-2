#include "RectangleToFill.h"
#include <array>

class FieldToChoice : public RectangleToFill
{
public:
	FieldToChoice(std::string name, const int sizeText, sf::Vector2f size, sf::Vector2f position, sf::Color ColorRec,
		sf::Color ColorText, std::string text, std::vector< std::pair<std::string, bool>> selectOptions);

	void drawRec(sf::RenderWindow& Window) override;

private:
	std::vector< RectanglText> m_selectOptions;
};