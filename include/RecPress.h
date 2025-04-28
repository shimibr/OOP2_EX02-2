#include <SFML/System/Vector2.hpp>
#include <string>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class RecPress
{
public:
	RecPress(sf::Vector2f position, sf::Vector2f size, std::string possibility, sf::Color color);
	RecPress(sf::Vector2f position,const int sizeText, std::string possibility, sf::Color color);
	void setColor();
	void setOutline(sf::Color color);
	std::string getPossibility() const;
	void drawRec(sf::RenderWindow& window);
	bool isRecPress(sf::Vector2f mousePos);
	void setIsSelected(bool isSelected) { m_isSelected = isSelected; }
	

private:
	sf::RectangleShape m_rec;
	sf::Text m_possibility;
	bool m_isSelected = false;
};