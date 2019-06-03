#pragma once
#include "myFunc.h"
#include "Object.h"

///This class can't move. Party is Neutral
class Brick :public Object
{
public:
	///Set position
	Brick(sf::Vector2f position);
	///Destructor
	virtual ~Brick();
	///Getter override
	const sf::Vector2f& GetPosition() const { return brick.getPosition(); }
	///Do nothing :)
	void Update(const float&);
	///Getter override
	const sf::Vector2f& GetSize() const { return brickSize; }
	///Draw in the Window
	void Draw(sf::RenderWindow &window);
private:
	///BrickSize
	const sf::Vector2f brickSize = sf::Vector2f(50.0f, 50.0f);
	///For SFML drawing
	sf::RectangleShape brick;
	///Brick image uploading in this variable and connected with RectangleShape
	sf::Texture brickTexture;

};

