#include "Game.h"

void Game::AddNewRectangle(float x , float y)
{
	sf::RectangleShape shape(sf::Vector2f(50.0f , 50.0f));
	shape.setPosition(x , y);
	players.push_back(shape);
}
bool Game::DoesExist(float x)
{
	for (int i = 0; i < players.size(); i++)
	{
		if (players[i].getPosition().x == x )
			return false;
	}
	return true;
}
Game::Game()
{
	SetWindow();
	float x;
	for (int i = 0; i < 4; i++)
	{
		x = (float)(rand() % window->getSize().x - 50.0f);
		while (DoesExist(x) != true)
		{
			 x = (float)(rand() % window->getSize().x - 50.0f);
		}
		AddNewRectangle(x, 0.0f);
	}


	
}

void Game::Draw()
{
	window->clear();
	for (auto e : players)
	{
		window->draw(e);
	}
	window->display();
	
}

void Game::Update(sf::Clock& clock)
{
	
	sf::Event evnt;
	while (window->pollEvent(evnt))
	{
		switch (evnt.type)
		{
		case sf::Event::Closed:
				window->close();
				break;
		}
	}
	if (clock.getElapsedTime().asSeconds() > 0.01)
	{
		for (auto e = players.begin() ; e != players.end(); e++)
		{
			e->move(sf::Vector2f(0.0f, 2.5f));
			if (e->getPosition().y == 400)
			{
				e->setPosition(900.0f, 900.0f);
			}
		}
		clock.restart();
	}
}

void Game::SetWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(600.0f , 800.0f), "Game1" , sf::Style::Close);
}

bool Game::GameRunning()
{
	return this->window->isOpen();
}
