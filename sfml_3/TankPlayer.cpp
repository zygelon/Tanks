#include "TankPlayer.h"

void TankPlayer::Update(const float& deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->Move(deltaTime, sides::Left);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->Move(deltaTime, sides::Right);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->Move(deltaTime, sides::Up);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->Move(deltaTime, sides::Down);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		Fire();
}

TankPlayer::~TankPlayer(){}
