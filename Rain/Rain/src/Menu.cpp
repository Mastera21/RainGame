#include "../header/Menu.h"
//C system headers

//C++ system headers
 
//Other libraries headers

//Own components headers

int32_t Menu::init(const sf::RenderWindow& window) {
	if (EXIT_SUCCESS != _startButton.init("Roboto-BoldItalic.ttf", "Start", sf::Vector2f(100.f, 40.f), 25, sf::Color::White, sf::Color::Black)) {
		std::cerr << "_startButton.init() failed.\n";
		return EXIT_FAILURE;
	}
	_startButton.setPos(sf::Vector2f(window.getSize().x / 2 - 50.f, window.getSize().y / 2 - 50.f));

	if (EXIT_SUCCESS != _exitButton.init("Roboto-BoldItalic.ttf", "End", sf::Vector2f(100.f, 40.f), 25, sf::Color::White, sf::Color::Black)) {
		std::cerr << "_exitButton.init() failed.\n";
		return EXIT_FAILURE;
	}
	_exitButton.setPos(sf::Vector2f(window.getSize().x / 2 - 50.f, window.getSize().y / 2.f));

	if (!_font.loadFromFile("Roboto-BoldItalic.ttf")) {
		std::cerr << "_font.loadFromFile() failed.\n";
		return EXIT_FAILURE;
	}

	_text.setFont(_font);
	_text.setString("Rain Game");
	_text.setCharacterSize(50);
	_text.setPosition(sf::Vector2f(window.getSize().x / 2 - 100.f, window.getSize().y / 2 - 300.f));

	return EXIT_SUCCESS;
}
void Menu::deinit() {

}
void Menu::handleEvent(const sf::RenderWindow& window, bool& isStartButtonPressed, bool& exitButton) {
	if (_startButton.isMouseHover(window)) {
		_startButton.setBackColor(sf::Color::Green);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			isStartButtonPressed = true;
		}
	}else {
		_startButton.setBackColor(sf::Color::White);
	}

	if (_exitButton.isMouseHover(window)) {
		_exitButton.setBackColor(sf::Color::Green);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			exitButton = false;
		}
	}else {
		_exitButton.setBackColor(sf::Color::White);
	}
}
void Menu::draw(sf::RenderWindow& window) {
	_startButton.draw(window);
	_exitButton.draw(window);
	window.draw(_text);
}
