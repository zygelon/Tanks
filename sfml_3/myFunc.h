#pragma once
#include "SFML\Graphics.hpp"

inline float abs(const sf::Vector2f& a)
{
	return sqrt(a.x*a.x + a.y*a.y);
}
