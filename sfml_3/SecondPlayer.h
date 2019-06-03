#pragma once


#pragma once
#include "Tank.h"
#include <iostream>
///For multiplayer gaming
class SecondPlayer :public Tank
{
public:
	///for testing
	SecondPlayer() : SecondPlayer(sf::Vector2f(600.0f, 600.0f)) {}//просто случайные числа
	///for playing
	SecondPlayer(sf::Vector2f tankPos) : Tank(tankPos, Parties::SPlayer ,sf::Color::Magenta, sf::Color::Green) {}
	///Destructor
	~SecondPlayer();
	///Is very similar to TankPlayer Update function
	void Update(const float &);
private:
};

