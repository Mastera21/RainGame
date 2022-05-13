#pragma once

//C system headers

//C++ system headers
#include <vector>
//Other libraries headers
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Font.hpp"
//Own components headers

//Forward declarations

class Score{
public:
	int32_t init(const sf::RenderWindow& window);
	void updateText(const std::string& input);
	void draw(sf::RenderWindow& window);
private:
	sf::Text _text;
	sf::Font _font;
};
