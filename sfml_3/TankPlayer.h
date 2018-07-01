#pragma once
#include "Tank.h"
#include <iostream>
class TankPlayer : Tank
{
public:
	TankPlayer() : TankPlayer(sf::Vector2f(400.0f, 400.0f)) {}//������ ��������� �����
	TankPlayer(sf::Vector2f tankPos) : Tank(tankPos,Parties::Good,sf::Color::Blue,sf::Color::White){}
	~TankPlayer();
	void Update(const float &);
private:
};
