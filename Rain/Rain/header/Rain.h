#pragma once
//C system headers

//C++ system headers
#include <vector>
//Other libraries headers
#include "SFML/Graphics/RenderWindow.hpp"
//Own components headers
#include "../header/Walls.h"
#include "../header/Player.h"
#include "../header/End.h"
#include "../header/ui/Score.h"
#include "../header/Menu.h"
//Forward declarations

#define numLines 300

class Rain{
public:
	Rain() = default;
	int32_t init(const sf::RenderWindow& window);
	void deinit();
	void draw(sf::RenderWindow& window);
	void handleEvent(const sf::RenderWindow& window, bool& endGame);
private:
	void resetRain(const sf::RenderWindow& window);
private:
	Walls _walls;
	Player _player;
	End _end;
	Score _score;
	Menu _menu;
private:
	std::vector<sf::RectangleShape> _rain{};
	int _speed;

	bool _isStartButtonPressed = false;
};

