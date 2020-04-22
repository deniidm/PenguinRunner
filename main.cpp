#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Collider.h"
#include "Game.h"
#include "Platform.h"
#include "Obstacle.h"
#include <vector>
int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML", sf::Style::Default | sf::Style::Resize | sf::Style::Close);
     
     sf::Texture playerTexture;
     playerTexture.loadFromFile("tux_from_linux.png");
     srand(time(NULL));
    
     Player player(&playerTexture, sf::Vector2u(3, 9), 0.3f , 100.0f , 150.f);
     float deltaTime = 0.0f;
     sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(650.0f, 650.0f));
     sf::Clock clock;
     sf::CircleShape circle;
     circle.setRadius(25.f);
     circle.setFillColor(sf::Color::Yellow);
     circle.setPosition(350.f, 100.f);
     std::vector<Platform> platforms;
     sf::Texture texture;
     texture.loadFromFile("03.png");
     sf::RectangleShape rect;
     rect.setSize(sf::Vector2f(50.f , 50.f));
     rect.setTexture(&texture);
     sf::Texture ground;
     sf::Texture obstacleTexture;
     
     obstacleTexture.loadFromFile("obstacle.png");
     Obstacle obstacle1(obstacleTexture);
     
     while (window.isOpen())
    {
        deltaTime = clock.getElapsedTime().asSeconds();
        if (deltaTime > 1.f / 20.f)
        {
            deltaTime = 1.f / 20.f;
        }
       
        clock.restart();
        sf::Event evnt;

        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
           
            }
      
        }
        player.Update(deltaTime);
        sf::Vector2f vector(player.GetPosition().x + 200.f, player.GetPosition().y);
        obstacle1.SetPostion(vector);
        platforms.push_back( Platform(nullptr, sf::Vector2f(1200.f, 250.f), sf::Vector2f(player.GetPosition().x , 500.f)));
        sf::Vector2f direction;
        for (Platform& platform : platforms)
        {
            if (platform.GetColider().checkColision(player.GetCollider(), direction, 1.f))
            {
                player.Collision(direction);
            }
        }
        
        
        view.setCenter(player.GetPosition().x + 250.f , player.GetPosition().y);
        window.clear(sf::Color(10, 191, 255));

        
        window.setView(view);
        player.Draw(window);
        obstacle1.Draw(window);
        for (Platform& platform : platforms)
        {
            platform.Draw(window);
        }
        circle.setPosition(player.GetPosition().x + 500.f, player.GetPosition().y - 300.f);
        rect.setPosition(player.GetPosition().x + 10.f, player.GetPosition().y );
        window.draw(circle);
        window.draw(rect);
        window.display();
        
    }
  
     /*Game game;
    
     
     while (game.GameRunning())
     {
         game.Update(clock);
         game.Draw();
     }
     */
    return 0;
}