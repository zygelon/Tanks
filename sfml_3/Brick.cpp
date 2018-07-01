#include "Brick.h"

Brick::Brick(sf::Vector2f position) : Object(Tags::Brick)
{
	brickTexture.loadFromFile("steel_brick.jpg");
	brick.setOrigin(brickSize / 2.0f);
	brick.setTexture(&brickTexture);
	brick.setSize(brickSize);
	brick.setPosition(position);

	/*global = Global::Access();
	global->AddBrick(this);*/
}


Brick::~Brick()
{
}

void Brick::Draw(sf::RenderWindow& window)
{
	window.draw(this->brick);
}

void Brick::Update(const float& deltaTime)
{
}