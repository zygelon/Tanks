#include "AI.h"

AI::AI() : AI(sf::Vector2f(200.0f, 200.0f)) {}

AI::AI(sf::Vector2f startPosition) : Tank(startPosition,Parties::Evil)
{
	lastPosition = sf::Vector2f(0.f, 0.f);
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
		if (clock.getElapsedTime().asSeconds() > r || GetPosition() == lastPosition)
			GenerMoving();
		lastPosition = GetPosition();
}

void AI::GenerMoving()
{
	 {
			direction = (sides)(rand() % 4);
			r = (rand() % 20)/10.0f;
			clock.restart();

	}
}
