#pragma once
#include "Animation.h"
#include "Collider.h"
class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed , float jumpHeight);
	void Update(float deltaTime);
	sf::Vector2f GetPosition();
	void Draw(sf::RenderWindow& window);
	void Rotate(sf::View& view, int counter);
	Collider GetCollider() { return Collider(body); };
	void Collision(sf::Vector2f direction);
private:
	float speed;
	unsigned int row;
	Animation animation;
	sf::RectangleShape body;
	bool faceRight;
	sf::Vector2f velocity;
	float jumpHeight;
	bool canJump;
};

