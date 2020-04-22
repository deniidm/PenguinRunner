#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <vector>
class Game
{
public:
	void AddNewRectangle(float x , float y);
	Game();
	void Draw();
	void Update(sf::Clock& clock);
	void SetWindow();
	bool GameRunning();
	bool DoesExist(float x);
private:
	std::vector<sf::RectangleShape> players;
	sf::RenderWindow* window;
};

