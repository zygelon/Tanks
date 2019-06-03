#pragma once
#include "Tank.h"
#include <cstdlib>
#include <ctime>
/*!
\brief All bots are using this class
\details Using just random)

*/
class AI : public Tank
{
public:
	///Just for testing
	AI();
	///Set spawn position
	AI(sf::Vector2f);
	///just destructor
	~AI();
	/*!
	\brief All AI in this function
	\details Fire every frame and moving in random direction while it can do it.
	*/
	void Update(const float &deltaTime);//переопределение апдейта что в танке
private:
	///Just Timer. Is using for random moving:)
	sf::Clock clock;
	/*!
	\brief Position in previous frame
	\details It is very cheap function to understand: can this tank move forward or not.
	*/
	sf::Vector2f lastPosition;
	///The time how long Tank will be moving forward
	float r; 
	///Generate moving timer and direction(just random)
	void GenerMoving();
	///The direction for moving
	sides direction;
};

