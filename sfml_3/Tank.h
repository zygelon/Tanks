#pragma once
#include <SFML\Graphics.hpp>
#include "Bullet.h"
#include "Object.h"


class Tank :public Object
{
public:
	Tank(sf::Vector2f pos, Parties party= Parties::Neutral,sf::Color bodyColor=sf::Color::Green,sf ::Color gunColor=sf::Color::Red, const int& hp=90, const int& damage = 30);
	Tank();
	virtual ~Tank();
	void Draw(sf::RenderWindow &window);
	void Move(const float&, sides);
	void Fire();
	virtual void Update(const float &deltaTime);
	
	

	//int GetDamage() { return damage; }
	void TakeDamage(const int& damage);

	const sf::Vector2f& GetSize() const { return bodySize; }
	const sf::Vector2f& GetPosition() const { return body.getPosition(); };
private:

	int hp;
	int damage;

	sides direction;
	
	const float speed = 160.0f;
	const sf::Vector2f startPos = sf::Vector2f(400.0f, 400.0f);
	const sf::Vector2f bodySize=sf::Vector2f(50.0f, 50.0f);
	
	float cooldownTime;
	sf::Clock cooldown;

	sf::RectangleShape body;
	sf::RectangleShape gun;
	
	bool CanMove(sides direction);
protected:
	sides GetDirection() { return direction; }
};
