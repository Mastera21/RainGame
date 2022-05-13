#include "../../header/ui/Score.h"
//C system headers

//C++ system headers
#include <iostream>
//Other libraries headers

//Own components headers

int32_t Score::init(const sf::RenderWindow& window) {
	if (!_font.loadFromFile("Roboto-BoldItalic.ttf")) {
		std::cerr << "Cant open this font: -> Score.cpp\n";
		return EXIT_FAILURE;
	}

	_text.setFont(_font);
	_text.setString("Health: Null");
	_text.setCharacterSize(40);

	return EXIT_SUCCESS;
}
void Score::updateText(const std::string& input) {
	_text.setString(input);
}
void Score::draw(sf::RenderWindow& window) {
	window.draw(_text);
}