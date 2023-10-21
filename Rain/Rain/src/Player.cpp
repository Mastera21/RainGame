#include "../header/Player.h"
//C system headers

//C++ system headers
#include <iostream>
//Other libraries headers

//Own components headers

int32_t Player::init(const sf::RenderWindow& window) {
	_player.setRadius(15.f);
	_player.setFillColor(sf::Color::Yellow);
	_player.setPosition(window.getSize().x - window.getSize().x, window.getPosition().y + 450.f);

	return EXIT_SUCCESS;
}

void Player::deinit() {}

void Player::move() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		_player.move(-_speed, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		_player.move(_speed, 0.f);
	}
}
void Player::collision(const sf::RenderWindow& window) {
	if (_player.getPosition().x < 0.f) {
		_player.setPosition(0.f, _player.getPosition().y);
	}
	if (_player.getPosition().x + _player.getGlobalBounds().width > window.getSize().x) {
		_player.setPosition(window.getSize().x - _player.getGlobalBounds().width, _player.getPosition().y);
	}
}
void Player::collideWithRain(sf::RectangleShape& rain) {
	if (rain.getGlobalBounds().intersects(_player.getGlobalBounds())) {
		_health--;
	}
}
void Player::checkForHealth(bool& endGame) {
	if (_health <= 0) {
		endGame = false;
	}
}
void Player::handleEvent(const sf::RenderWindow& window, sf::RectangleShape& rain, bool& endGame) {
	move();
	collision(window);
	collideWithRain(rain);
	checkForHealth(endGame);
}
void Player::draw(sf::RenderWindow& window) {
	window.draw(_player);
}
sf::CircleShape Player::getPlayer() const {
	return _player;
}
int Player::getHealth() const {
	return _health;
}
