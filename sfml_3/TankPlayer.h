#pragma once
#include "Tank.h"
#include <iostream>
/*!
\brief This tank is controlled by user.
\details Very important function is Update
*/
class TankPlayer : public Tank
{
public:
	///Just for testing
	TankPlayer() : TankPlayer(sf::Vector2f(400.0f, 400.0f)) {}//просто случайные числа
	///Constructor
	TankPlayer(sf::Vector2f tankPos) : Tank(tankPos,Parties::FPlayer,sf::Color::Blue,sf::Color::White,90,50){}
	///Destructor
	~TankPlayer();
	/*!
	\brief sets up keys controlling for user
	\details For moving is using Tank's Move()
	*/
	void Update(const float &);
private:
};

