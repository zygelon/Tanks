#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "myFunc.h"
#include "Global.h"
#include "Object.h"

class Bullet : Object
{
public:
	Bullet(sf::Vector2f position, sides,Parties);
	~Bullet();
	const sf::Vector2f& GetSize() const { return bulletSize; }
	const sf::Vector2f& GetPosition() const { return bullet.getPosition(); }
	void Update(const float&);
	bool IsOutOfRange();
	void Draw(sf::RenderWindow& window);
private:
	//Global * global;
	sides direction;
	sf::RectangleShape bullet;

	const sf::Vector2f bulletSize = sf::Vector2f(15.0f, 15.0f);

	const float offset = 50.0f;
	 float speed = 500.0f;
};
