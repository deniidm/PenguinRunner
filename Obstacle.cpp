#include "Obstacle.h"
Obstacle::Obstacle(sf::Texture& texture, int speed)
{
	body.setSize(sf::Vector2f(50.f, 50.f));
	body.setTexture(&texture);
	this->speed = speed;
}

void Obstacle::SetPostion(sf::Vector2f vector)
{
	if (set == false)
	{
		body.setPosition(vector);
		set = true;
	}
}
void Obstacle::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
void Obstacle::Update(float deltaTime)
{
	sf::Vector2f velocity;
	velocity.x = -speed * deltaTime;
	velocity.y = 0;
	body.move(velocity);
}


void Obstacle::UpdateTexture(sf::Texture& texture1, sf::Texture& texture2)
{
	if (movement == false)
	{
		movement = true;
		body.setTexture(&texture1);
	}
	else
	{
		movement = false;
		body.setTexture(&texture2);
	}
}
