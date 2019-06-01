#include "WorldGeneration.h"

void WorldGeneration::GenerateSingleGame()
{
	for (float i = 25.0f; i < WINDOW_LENGTH; i += 50.0f)//50.0f размер блока
	{
		new Brick(sf::Vector2f(i, 25.0f));
		new Brick(sf::Vector2f(i, WINDOW_HEIGHT - 25.0f));
	}
	for (float i = 25.0f; i < WINDOW_HEIGHT; i += 50.0f)
	{
		new Brick(sf::Vector2f(25.0f, i));//25.0 половина размера блока
		new Brick(sf::Vector2f(WINDOW_LENGTH - 25.0f, i));
	}
	srand(time(0));
	//new TankPlayer(sf::Vector2f(400.0f, 100.0f));
	new TankPlayer(sf::Vector2f(WINDOW_LENGTH/2, WINDOW_HEIGHT/2));
	//new SecondPlayer(sf::Vector2f(rand() % (WINDOW_LENGTH - 150) + 75, rand() % (WINDOW_HEIGHT - 150) + 75));
	for (int i = 0; i < 2; ++i)
	{
		new AI(sf::Vector2f(90.f, 90.f) + sf::Vector2f(55.f, 55.f)*i);
		new AI(sf::Vector2f(140.f, 230.f) + sf::Vector2f(55.f, 55.f)*i);
		new AI(sf::Vector2f(230.f, 90.f) + sf::Vector2f(55.f, 55.f)*i);
	}
	new AI(sf::Vector2f(90.f, 90.f) + sf::Vector2f(55.f, 55.f)*2);

	for (int i = 0; i < 3; ++i)
	{
		new AI(sf::Vector2f(WINDOW_LENGTH-90.f, WINDOW_HEIGHT - 90.f) - sf::Vector2f(55.f, 55.f)*i);
		new AI(sf::Vector2f(WINDOW_LENGTH-140.f, WINDOW_HEIGHT - 230.f) - sf::Vector2f(55.f, 55.f)*i);
		new AI(sf::Vector2f(WINDOW_LENGTH-230.f,WINDOW_HEIGHT- 90.f) - sf::Vector2f(55.f, 55.f)*i);
	}
	new AI(sf::Vector2f(WINDOW_LENGTH-90.f, WINDOW_HEIGHT - 90.f) - sf::Vector2f(55.f, 55.f) * 3);
}

void WorldGeneration::GenerateMultiplayerGame()
{

	for (float i = 25.0f; i < WINDOW_LENGTH; i += 50.0f)//50.0f размер блока
	{
		new Brick(sf::Vector2f(i, 25.0f));
		new Brick(sf::Vector2f(i, WINDOW_HEIGHT - 25.0f));
	}
	for (float i = 25.0f; i < WINDOW_HEIGHT; i += 50.0f)
	{
		new Brick(sf::Vector2f(25.0f, i));//25.0 половина размера блока
		new Brick(sf::Vector2f(WINDOW_LENGTH - 25.0f, i));
	}
	srand(time(0));
	//new TankPlayer(sf::Vector2f(400.0f, 100.0f));
	new TankPlayer(sf::Vector2f(WINDOW_LENGTH-100.f,WINDOW_HEIGHT-100.f));
	new SecondPlayer(sf::Vector2f(100.f, 100.f));

}