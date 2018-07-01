#include "AI.h"

AI::AI() : AI(sf::Vector2f(200.0f, 200.0f)) {}

AI::AI(sf::Vector2f startPosition) : Tank(startPosition,Parties::Evil)
{
	r = (rand() % 20)/10.0f;
	direction = (sides)(rand() % 4);
}

AI::~AI()
{
}

void AI::Update(const float &deltaTime)
{
		Fire();
		this->Move(deltaTime, direction);
		if (clock.getElapsedTime().asSeconds() > r) {
			direction = (sides)(rand() % 4);
			r = (rand() % 20)/10.0f;
			clock.restart();

		}
}
