#pragma once

//C system headers

//C++ system headers
#include <iostream>
//Other libraries headers
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Font.hpp"
//Own components headers
#include "../header/Button.h"
//Forward declarations

class Menu{
public:
	int32_t init(const sf::RenderWindow& window);
	void deinit();
	void handleEvent(const sf::RenderWindow& window, bool& isStartButtonPressed, bool& exitButton);
	void draw(sf::RenderWindow& window);
private:
	Button _startButton;
	Button _exitButton;

	sf::Text _text;
	sf::Font _font;
};

