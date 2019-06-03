#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include <forward_list>

///Base class for every object that can be visible on window. Abstract class
class Object
{
public:
	///4 Sides where Tank can move.
	enum class sides { Up, Down, Left, Right };
	///Parties need to understand which an object can destroy which another an object
	enum class Parties { FPlayer, Evil, Neutral, SPlayer };

	/*!
	\brief To understand that is collision between 2 objects or not.
	\details Every actor consists of one rectangle and it is easy to check collision 
	
	*/
	friend bool IsCollision(const Object&,const Object&) ;
	///Constructor
	Object(Parties party=Parties::Neutral);
	///Destructor
	virtual ~Object();
	///To understand, will  this object be deleted
	bool IsDead() { return isDead; }
	///Give access to object array.
	static const std::forward_list<Object*>& GetObjects() { return objects; }
	///Getter to property "party"
	Parties GetParty() { return party; }
	///Destroyed objects which has isDead==True
	static void DestroyDeadObjects();

	///Overrides in son
	virtual const sf::Vector2f& GetSize() const = 0;
	///Overrides in son
	virtual const sf::Vector2f& GetPosition() const = 0;
	/*!
	\brief Overrides in son.
	\details very important function. It executes every frame in every an object. Responsible for main game logic
	*/
	virtual void Update(const float &deltaTime) = 0;
	/*!
	\brief Overrides in son.
	\details important function. It executes every frame in every an object. Responsible for drawing objects in the window.
	*/
	virtual void Draw(sf::RenderWindow &window) = 0;
	///It says that this object will be destroyed be DestroyDeadObject() function
	void MakeDead() { if(!isDead) isDead = true; }

private:
	///To don't allow Enemy tank kill enemy tank or other cases
	Parties party;
	///All objects are stored in this list.
	static  std::forward_list<Object*>objects;
	///To understand, will  this object be deleted
	bool isDead = false;

protected:
};

