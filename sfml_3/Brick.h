#pragma once
#include "myFunc.h"
#include "Object.h"
//class Global;
//#include "Global.h"

class Brick : Object
{
public:
	Brick(sf::Vector2f position);
	virtual ~Brick();
	const sf::Vector2f& GetPosition() const { return brick.getPosition(); }
	void Update(const float&);
	const sf::Vector2f& GetSize() const { return brickSize; }
	void Draw(sf::RenderWindow &window);
private:
	const sf::Vector2f brickSize = sf::Vector2f(50.0f, 50.0f);
	sf::RectangleShape brick;
	sf::Texture brickTexture;

};

