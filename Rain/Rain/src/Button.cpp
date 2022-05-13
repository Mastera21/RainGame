#include "../header/Button.h"

//C system headers

//C++ system headers
#include <iostream>
//Other libraries headers

//Own components headers

int32_t Button::init(const std::string& path, const std::string& text, const sf::Vector2f& size, int textSize, sf::Color bgColor, sf::Color textColor) {
	if (!_font.loadFromFile(path)) {
		std::cerr << "Cannot open font for file -> Button::init()\n";
	}
	_text.setString(text);
	_text.setFont(_font);
	_text.setFillColor(textColor);
	_text.setCharacterSize(textSize);
	_button.setSize(size);
	_button.setFillColor(bgColor);

	return EXIT_SUCCESS;
}

void Button::setBackColor(sf::Color color) {
	_button.setFillColor(color);
}

void Button::setTextColor(sf::Color color) {
	_text.setFillColor(color);
}

void Button::setPos(sf::Vector2f pos) {
	_button.setPosition(pos);

	float xPos = (pos.x + _button.getLocalBounds().width / 2) - (_text.getLocalBounds().width / 2);
	float yPos = (pos.y + _button.getLocalBounds().height / 2) - (_text.getLocalBounds().height / 2);
	_text.setPosition({ xPos, yPos });
}

void Button::draw(sf::RenderWindow& _window) {
	_window.draw(_button);
	_window.draw(_text);
}

bool Button::isMouseHover(const sf::RenderWindow& window) {
	int mouseX = sf::Mouse::getPosition(window).x;
	int mouseY = sf::Mouse::getPosition(window).y;
	
	float btnPosX = _button.getPosition().x;
	float btnPosY = _button.getPosition().y;

	int btnxPosWidth = _button.getPosition().x + _button.getLocalBounds().width;
	int btnyPosHeight = _button.getPosition().y + _button.getLocalBounds().height;

	if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY) {
		return true;
	}
	return false;
}
