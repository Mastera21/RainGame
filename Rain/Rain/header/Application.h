#pragma once

//C system headers

//C++ system headers

//Other libraries headers
#include "SFML/Window/Event.hpp"
//Own components headers
#include "../header/Rain.h"
//Forward declarations

class Application{
public:
	Application(Application&) = delete;

	static Application& Get() {
		static Application instance;
		return instance;
	}
	static void run() {
		Get().main();
	}

private:
	Application() = default;
	int32_t init();
	void deinit();
	void main();
	void update(sf::Event& e, bool& endGame);
	void handleEvent(bool& endGame);
	void drwa();
	bool requestForExit(const sf::Event& e, bool& endGame);
private:
	Rain _rain;
private:
	sf::RenderWindow _window;
	bool _endGame = false;
};

