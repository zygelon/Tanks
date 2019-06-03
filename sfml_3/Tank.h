#pragma once
#include <SFML\Graphics.hpp>
#include "Bullet.h"
#include "Object.h"

/*!
\brief All tanks are inherited from this class
\details You can create an object from this class. 
It can move and fire.
*/
class Tank :public Object
{
public:
	///Destructor. It used in by inherited classes.
	Tank(sf::Vector2f pos, Parties party= Parties::Neutral,sf::Color bodyColor=sf::Color::Green,sf ::Color gunColor=sf::Color::Red, const int& hp=90, const int& damage = 30);
	///For testing
	Tank();
	///Destructor
	virtual ~Tank();
	///For drawing in the window
	void Draw(sf::RenderWindow &window);
	///Allow to change position. Executes in update.
	void Move(const float&, sides);
	///Creates Bullet object 
	void Fire();
	///Overrides in son. In this case doing nothing. \details Executes every frame
	virtual void Update(const float &deltaTime);
	
	

	///hp-=damage. If damage<0 tank will be destroyed. \details executes in Global
	void TakeDamage(const int& damage);
	///Overrided Getter for size
	const sf::Vector2f& GetSize() const { return bodySize; }
	///Overrided Getter for position
	const sf::Vector2f& GetPosition() const { return body.getPosition(); };
private:
	///Tank hp
	int hp;
	///Tank damage
	int damage;
	///the direction to moving
	sides direction;
	///Tank speed
	const float speed = 160.0f;
	///Size of tank mesh: vertical and horizontal
	const sf::Vector2f bodySize=sf::Vector2f(50.0f, 50.0f);
	///Time which need to reload gun
	float cooldownTime;
	///Just need to cooldownTime
	sf::Clock cooldown;
	///Mesh for body
	sf::RectangleShape body;
	///Mesh for gun
	sf::RectangleShape gun;
	/*!
	\brief Need to understand can this tank move in selected direction;
	\details It uses Object Forward list and check between this tank and any object
	*/
	bool CanMove(sides direction);
protected:
	///Getter for direction
	sides GetDirection() { return direction; }
};
