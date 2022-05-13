#include "../header/End.h"

//C system headers

//C++ system headers
#include <iostream>
//Other libraries headers

//Own components headers

int32_t End::init(const sf::RenderWindow& window) {
	_end.setSize(sf::Vector2f(30.f, 30.f));
	_end.setPosition(sf::Vector2f(window.getSize().x / 2.f + 410.f, window.getSize().y / 2.f + 365.f));
	_end.setFillColor(sf::Color::Red);

	return EXIT_SUCCESS;
}
void End::deinit() {

}
void End::handleEvent(sf::CircleShape& player, bool& endGame) {
	if (_end.getGlobalBounds().intersects(player.getGlobalBounds())) {
		endGame = false;
	}
}
void End::draw(sf::RenderWindow& window) {
	window.draw(_end);
}
