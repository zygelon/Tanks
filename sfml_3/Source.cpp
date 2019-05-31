#include <SFML\Graphics.hpp>
#include <iostream>
#include "Global.h"
#include "Brick.h"
#include "AI.h"
#include "TankPlayer.h"
#include "SecondPlayer.h"

void GenerateWorld()
{
	for (float i = 25.0f; i < WINDOW_LENGTH; i += 50.0f)//50.0f размер блока
	{
		new Brick(sf::Vector2f(i, 25.0f));
		new Brick(sf::Vector2f(i, WINDOW_HEIGHT - 25.0f));
	}
	for (float i = 25.0f; i < WINDOW_HEIGHT; i += 50.0f)
	{
		new Brick(sf::Vector2f(25.0f,i));//25.0 половина размера блока
		new Brick(sf::Vector2f(WINDOW_LENGTH-25.0f,i));
	}
	srand(time(0));
	//new TankPlayer(sf::Vector2f(400.0f, 100.0f));
	new TankPlayer(sf::Vector2f(rand() % (WINDOW_LENGTH - 150) + 75, rand() % (WINDOW_HEIGHT - 150) + 75));
	new SecondPlayer(sf::Vector2f(rand() % (WINDOW_LENGTH - 150) + 75, rand() % (WINDOW_HEIGHT - 150) + 75));
	for (int i = 0; i < 1; ++i)
	{
		new AI(sf::Vector2f(rand() % (WINDOW_LENGTH - 150) + 75, rand() % (WINDOW_HEIGHT - 150) + 75));
	}
}

int main()
{
	GenerateWorld();
	sf::RenderWindow window(sf::VideoMode(WINDOW_LENGTH,WINDOW_HEIGHT), "tanks",sf::Style::Close);
	//new Tank(sf::Vector2f(100.0f, 100.0f));
	Global *global = Global::Access();
	while (window.isOpen())
	{
		sf::Event ev;
		while (window.pollEvent(ev))
			if (ev.type == sf::Event::Closed || ev.type==sf::Event::KeyPressed && ev.key.code==sf::Keyboard::Escape) window.close();
		window.clear(sf::Color::Transparent);

		global->Update();
		global->Draw(window);

		window.display();
	}
}