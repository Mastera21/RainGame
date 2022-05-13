//C system headers

//C++ system headers

//Other libraries headers
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Window/Mouse.hpp"
//Own components headers

//Forward declarations

class Button {
public:
	int32_t init(const std::string& path, const std::string& text, const sf::Vector2f& size, int textSize, sf::Color bgColor, sf::Color textColor);

	void setBackColor(sf::Color color);
	void setTextColor(sf::Color color);
	void setPos(sf::Vector2f pos);
	void draw(sf::RenderWindow& _window);

	bool isMouseHover(const sf::RenderWindow& _window);
private:
	sf::RectangleShape _button;
	sf::Text _text;
	sf::Font _font;
};
