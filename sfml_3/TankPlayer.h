#pragma once
#include "Tank.h"
#include <iostream>
class TankPlayer : public Tank
{
public:
	TankPlayer() : TankPlayer(sf::Vector2f(400.0f, 400.0f)) {}//просто случайные числа
	TankPlayer(sf::Vector2f tankPos) : Tank(tankPos,Parties::FPlayer,sf::Color::Blue,sf::Color::White){}
	~TankPlayer();
	void Update(const float &);
private:
};

