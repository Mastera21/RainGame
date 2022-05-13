#pragma once
//C system headers

//C++ system headers

//Other libraries headers
 
//Own components headers
#include "../header/Line.h"
//Forward declarations

#define numWalls 3

class Walls{
public:
	int32_t init(const sf::RenderWindow& window);
	void deinit();
	void handleEvent(const sf::RenderWindow& window, sf::RectangleShape& rain);
	void draw(sf::RenderWindow& window);
	void collisionWithRain(const sf::RenderWindow& window, sf::RectangleShape& rain);
private:
	void moveWalls(const sf::RenderWindow& window, const int& index);
private:
	sf::Vector2f _velocity;
	sf::Vector2f _wallsPos;
	std::vector<Line> _walls{};
private:
	bool _touchLeftWall;
	bool _touchRightWall;
	double _speed;
};

