#include "../header/Line.h"

//C system headers

//C++ system headers
 
//Other libraries headers

//Own components headers

void Line::setPos(float x, float y) {
	_line.setPosition(sf::Vector2f(x,y));
}
void Line::setSize(const sf::Vector2f& size) {
	_line.setSize(size);
}
void Line::setColor(const sf::Color& color) {
	_line.setFillColor(color);
}
void Line::rotate(const float& angle) {
	_line.rotate(angle);
}
void Line::move(const float& x, const float& y) {
	_line.move(sf::Vector2f(x,y));
}
void Line::draw(sf::RenderWindow& window) {
	window.draw(_line);
}
sf::FloatRect Line::isInteracting() const {
	return _line.getGlobalBounds();
}
sf::Vector2f Line::getPos() {
	return _line.getPosition();
}