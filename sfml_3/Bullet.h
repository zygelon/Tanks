#pragma once
#include <iostream>
#include "../SFML/Graphics.hpp"
#include "myFunc.h"

#include "Object.h"

/*!
\brief Just a gun bullet
\details Object from this class creates when tank firing
*/
class Bullet : public Object
{
public:
	///Sets start position, moving vector(side) and bullet damage
	Bullet(sf::Vector2f position, sides,Parties,const int& damage);
	///Destructor
	~Bullet();
	///Overrided getter for bullet size
	const sf::Vector2f& GetSize() const { return bulletSize; }
	///Overrided getter for bullet position
	const sf::Vector2f& GetPosition() const { return bullet.getPosition(); }
	/*!
	\brief Every frame move bullet.
	*/
	void Update(const float&);
	///Getter for damage
	int GetDamage() const { return damage; }
	///Is bullet is too far? If yes class global execute the destructor.
	bool IsOutOfRange();
	///For drawing in the window
	void Draw(sf::RenderWindow& window);
private:
	///The damage to tank
	int damage;
	///Flying bullet direction
	sides direction;
	///Mesh of the bullet
	sf::RectangleShape bullet;
	///Bullet is a rectangle. This is its size.
	const sf::Vector2f bulletSize = sf::Vector2f(15.0f, 15.0f);
	/// \details The bullet spawns nearby a Tank. The distance between them is an offset
	const float offset = 50.0f;
	///Bullet speed
	 float speed = 500.0f;
};
