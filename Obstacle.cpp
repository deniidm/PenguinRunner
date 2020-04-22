#include "Obstacle.h"
Obstacle::Obstacle(sf::Texture& texture)
{
	body.setSize(sf::Vector2f(50.f, 50.f));
	body.setTexture(&texture);
}

void Obstacle::SetPostion(sf::Vector2f vector)
{
	body.setPosition(vector);
}
void Obstacle::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
