#include "RectanglText.h"

class RectangleToFill : public RectanglText
{
public:
	RectangleToFill(std::string name, const int sizeText, sf::Vector2f size, sf::Vector2f position, sf::Color ColorRec, sf::Color ColorText, std::string text);

	void drawRec(sf::RenderWindow& Window) override;
	
private:
	RectanglText m_textName;
};