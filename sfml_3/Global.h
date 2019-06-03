#pragma once
#include <forward_list>
#include <SFML\Graphics.hpp>
#include "Object.h"
#include "myFunc.h"
using namespace std;

/*!
\brief this class appeals to every object
\details It executes Update() and Draw() function in every object, every frame.
*/
class Global
{
public:
	///pattern Singleton
	static Global* Access();
	///executes all Update() in Objects List
	void Update();
	///executes all Draw() in Objects List
	void Draw(sf::RenderWindow& window);
	

private:
	/// to get deltaTime(time betweet frames)
	sf::Clock clock;
	///Constructor
	Global();
	///Destructor
	~Global();
	///Singleton
	Global(Global const&) = delete;
	Global& operator=(Global const&) = delete;
};