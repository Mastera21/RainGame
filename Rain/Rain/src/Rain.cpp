#include "../header/Rain.h"
//C system headers

//C++ system headers
#include <iostream>
//Other libraries headers

//Own components headers

int32_t Rain::init(const sf::RenderWindow& window) {
    _rain.reserve(numLines);
    for (float i = 0; i < numLines; ++i) {
        sf::RectangleShape rect;
        rect.setSize(sf::Vector2f(2.f, 15.f));
        rect.setPosition((float)(rand() % window.getSize().x), (float)(rand() % -400 + (-400)));
        rect.setFillColor(sf::Color::Cyan);
        _rain.emplace_back(rect);
    }

    if (EXIT_SUCCESS != _walls.init(window)) {
        std::cerr << "Error, _walls.init() failed.\n";
        return EXIT_FAILURE;
    }

    if (EXIT_SUCCESS != _player.init(window)) {
        std::cerr << "Error, _player.init() failed.\n";
        return EXIT_FAILURE;
    }

    if (EXIT_SUCCESS != _end.init(window)) {
        std::cerr << "Error, _end.init() failed.\n";
        return EXIT_FAILURE;
    }

    if (EXIT_SUCCESS != _score.init(window)) {
        std::cerr << "Error, _score.init() failed.\n";
        return EXIT_FAILURE;
    }

    if (EXIT_SUCCESS != _menu.init(window)) {
        std::cerr << "Error, _menu.init() failed.\n";
        return EXIT_FAILURE;
    }

	return EXIT_SUCCESS;
}
void Rain::deinit() {
    _rain.clear();
    _end.deinit();
    _player.deinit();
    _walls.deinit();
}
void Rain::resetRain(const sf::RenderWindow& window) {
    //This function return rain back to the top on window when hits the ground
    for (int i = 0; i < numLines; ++i) {
        if (_rain[i].getPosition().y > window.getSize().y) {
            _rain[i].setPosition((float)(rand() % window.getSize().x), (float)(rand() % -400 + (-400)));
        }
    }
}
void Rain::handleEvent(const sf::RenderWindow& window, bool& endGame) {
    for (int i = 0; i < numLines; ++i) {
        _speed = rand() % 20;
        _rain[i].move(0.f, (float)(_speed));

        if (_isStartButtonPressed) {
            _walls.handleEvent(window, _rain[i]);
            _player.handleEvent(window, _rain[i], endGame);
            _end.handleEvent(_player.getPlayer(), endGame);
        }else {
            _menu.handleEvent(window, _isStartButtonPressed, endGame);
        }

        resetRain(window);
    }
    _score.updateText("Health: " + std::to_string(_player.getHealth()));
}
void Rain::draw(sf::RenderWindow& window) {
    for (const auto& i : _rain) {
        window.draw(i);
    }

    if (_isStartButtonPressed) {
        _walls.draw(window);
        _player.draw(window);
        _end.draw(window);
        _score.draw(window);
    }else {
        _menu.draw(window);
    }
}