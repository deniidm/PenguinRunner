#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Obstacle
{
public:
	Obstacle(sf::Texture&texture , int speed);
	void SetPostion(sf::Vector2f);
	void Draw(sf::RenderWindow& window);
	void Update(float deltaTime);
	void UpdateTexture(sf::Texture& texture1, sf::Texture& texture2);
	
private:
	sf::RectangleShape body;
	bool set = false;
	int speed;
	bool movement = false;
};

