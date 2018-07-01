#pragma once
#include <forward_list>
#include <SFML\Graphics.hpp>
#include "Object.h"
#include "myFunc.h"
using namespace std;

const int WINDOW_LENGTH = 1200;
const int WINDOW_HEIGHT = 800;
class Global
{
public:
	static Global* Access();
	void Update();
	void Draw(sf::RenderWindow& window);
	

private:
	sf::Clock clock;
	Global();
	~Global();

	Global(Global const&) = delete;
	Global& operator=(Global const&) = delete;
};