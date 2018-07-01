#include "TankPlayer.h"

void TankPlayer::Update(const float& deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->Move(deltaTime, sides::Left);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->Move(deltaTime, sides::Right);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->Move(deltaTime, sides::Up);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->Move(deltaTime, sides::Down);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		Fire();
}

TankPlayer::~TankPlayer(){}
