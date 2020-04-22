#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Obstacle
{
public:
	Obstacle(sf::Texture&texture);
	void SetPostion(sf::Vector2f);
	void Draw(sf::RenderWindow& window);
private:
	sf::RectangleShape body;
};

