#include "../header/Application.h"

//C system headers

//C++ system headers
#include <iostream>
//Other libraries headers

//Own components headers

int32_t Application::init() {
    _window.create(sf::VideoMode(900, 800), "Rain");
    _window.setFramerateLimit(60);

    if (EXIT_SUCCESS != _rain.init(_window)) {
        std::cerr << "Error, _rain.init() failed.\n";
        return EXIT_FAILURE;
    }

    _endGame = true;

	return EXIT_SUCCESS;
}
void Application::deinit() {
    _rain.deinit();
}
void Application::main() {
	if (EXIT_SUCCESS != init()) {
		std::cerr << "Error, init() faield.\n";
		return;
	}

    while (_endGame) {
        sf::Event e;
        update(e, _endGame);
        drwa();
    }
    deinit();
}
void Application::update(sf::Event& e, bool& endGame) {
    while (_window.pollEvent(e)) {
        if (requestForExit(e, endGame)) {
            _window.close();
            break;
        }
    }
    handleEvent(endGame);
}
bool Application::requestForExit(const sf::Event& e, bool& endGame) {
    switch (e.type) {
    case sf::Event::Closed:
        _window.close();
        endGame = false;
        return true;
        break;
    case sf::Event::KeyPressed:
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            _window.close();
            endGame = false;
            return true;
        }
        break;
    case sf::Event::Resized:
        break;
    default:
        break;
    }
    return false;
}
void Application::handleEvent(bool& endGame) {
    _rain.handleEvent(_window, endGame);
}
void Application::drwa() {
    _window.clear();
    _rain.draw(_window);
    _window.display();
}
