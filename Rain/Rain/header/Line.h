#pragma once
//C system headers

//C++ system headers

//Other libraries headers
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
//Own components headers

//Forward declarations

class Line{
public:
	Line() {}
	virtual ~Line() = default;
	void draw(sf::RenderWindow& window);
	void setPos(float x, float y);
	void setSize(const sf::Vector2f& size);
	void setColor(const sf::Color& color);
	void rotate(const float& angle);
	void move(const float& x, const float& y);
	sf::FloatRect isInteracting() const;
	sf::Vector2f getPos();
private:
	sf::RectangleShape _line;
};

