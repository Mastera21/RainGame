#pragma once
//C system headers

//C++ system headers

//Other libraries headers
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
//Own components headers

//Forward declarations

class End{
public:
	int32_t init(const sf::RenderWindow& window);
	void deinit();
	void handleEvent(sf::CircleShape& player, bool& endGame);
	void draw(sf::RenderWindow& window);
private:
	sf::RectangleShape _end;
};

