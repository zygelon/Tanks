#pragma once


#pragma once
#include "Tank.h"
#include <iostream>
class SecondPlayer : Tank
{
public:
	SecondPlayer() : SecondPlayer(sf::Vector2f(600.0f, 600.0f)) {}//просто случайные числа
	SecondPlayer(sf::Vector2f tankPos) : Tank(tankPos, Parties::Good, sf::Color::Magenta, sf::Color::Green) {}
	~SecondPlayer();
	void Update(const float &);
private:
};

