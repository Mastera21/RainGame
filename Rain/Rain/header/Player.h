#pragma once
//C system headers

//C++ system headers

//Other libraries headers
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Window/Event.hpp"
//Own components headers

//Forward declarations

class Player{
public:
	int32_t init(const sf::RenderWindow& window);
	void deinit();
	void draw(sf::RenderWindow& window);
	void handleEvent(const sf::RenderWindow& window, sf::RectangleShape& rain, bool& endGame);

	int getHealth() const;
	sf::CircleShape getPlayer() const;

private:
	void move();
	void collision(const sf::RenderWindow& window);
	inline void collideWithRain(sf::RectangleShape& rain);
	inline void checkForHealth(bool& endGame);
private:
	sf::Vector2f _velocity;
	float _speed = 0.04f;
	int _health = 100;
private:
	sf::CircleShape _player;
};

