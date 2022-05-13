#include "../header/Walls.h"

//C system headers

//C++ system headers
#include <iostream>
//Other libraries headers
 
//Own components headers

int32_t Walls::init(const sf::RenderWindow& window) {
    _walls.reserve(numWalls);
    for (int i = 0; i < numWalls; ++i) {
        Line w;
        _walls.emplace_back(w);
    }
    _walls[0].setColor(sf::Color::Green);
    //_walls[0].setPos(window.getSize().x / 2 - 100, window.getSize().y / 2 + 100);
    _walls[0].setSize(sf::Vector2f(230.f, 10.f));

    _walls[1].setColor(sf::Color::Red);
    _walls[1].setPos(window.getSize().x / 2.f - 450.f, window.getSize().y / 2.f);
    _walls[1].setSize(sf::Vector2f(200.f, 10.f));

    _walls[2].setColor(sf::Color::Blue);
    _walls[2].setPos((float)(window.getSize().x / 2 + 150), (float)(window.getSize().y / 2 - 40));
    _walls[2].setSize(sf::Vector2f(200.f, 10.f));

    _speed = 0.01;

    _wallsPos = sf::Vector2f((float)(window.getSize().x / 2 - 100), (float)(window.getSize().y / 2 + 100));

	return EXIT_SUCCESS;
}
void Walls::deinit() {
    _walls.clear();
}
inline void Walls::collisionWithRain(const sf::RenderWindow& window, sf::RectangleShape& rain) {
    for (int i = 0; i < _walls.size(); ++i) {
        if (rain.getGlobalBounds().intersects(_walls[i].isInteracting())) {
            rain.setPosition((float)(rand() % window.getSize().x), (float)(rand() % -400 + (-400)));
        }
    }
}
inline void Walls::moveWalls(const sf::RenderWindow& window, const int& index) {
    if (_walls[index].getPos().x < 0 || _walls[index].getPos().x + _walls[index].isInteracting().width > window.getSize().x) {
        _speed *= -1;
    }
    _wallsPos.x += (float)(_speed);
    _walls[index].setPos(_wallsPos.x, _wallsPos.y);
}
void Walls::handleEvent(const sf::RenderWindow& window, sf::RectangleShape& rain) {
    collisionWithRain(window, rain);
    moveWalls(window, 0);
}
void Walls::draw(sf::RenderWindow& window) {
    for (int i = 0; i < _walls.size(); ++i) {
        _walls[i].draw(window);
    }
}

