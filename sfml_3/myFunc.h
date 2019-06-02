#pragma once
#include "SFML\Graphics.hpp"

const int WINDOW_LENGTH = 1200;
const int WINDOW_HEIGHT = 800;

inline float abs(const sf::Vector2f& a)
{
	return sqrt(a.x*a.x + a.y*a.y);
}

inline sf::Vector2f operator*(float b,sf::Vector2f a)
{
	return a * b;
}

inline sf::Vector2f operator*(sf::Vector2f a, float b)
{
	return sf::Vector2f(a.x*b, a.y*b);
}