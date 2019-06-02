#include "Tank.h"

using namespace std;

Tank::Tank(sf::Vector2f pos,Parties party,sf::Color bodyColor,sf ::Color gunColor,const int& hp,const int& damage) : Object(Tags::Tank,party), hp(hp),damage(damage)
{


	body.setSize(bodySize);
	body.setPosition(pos);
	body.setOrigin(body.getSize() / 2.0f);
	body.setFillColor(bodyColor);

	gun.setSize(sf::Vector2f(bodySize.x / 3.0f, bodySize.y ));
	gun.setOrigin(gun.getSize() / 2.0f);
	gun.setPosition(body.getPosition()-sf::Vector2f(0.0f,bodySize.y/2.0f));
	gun.setFillColor(gunColor);

	direction = sides::Up;

	cooldownTime = 0.5f;
}

Tank::Tank() : Tank(sf::Vector2f(400.0f, 400.0f)){}

Tank::~Tank()
{
}

void Tank::Draw(sf::RenderWindow &window)
{
	window.draw(body);
	window.draw(gun);
}

void Tank::Move(const float& deltaTime, sides direction)
{
	if (!CanMove(direction)) return;
	switch (direction)
	{
	case sides::Up:
		this->direction = sides::Up;
		gun.setRotation(0.0f);
		body.setRotation(0.0f);
		body.move(sf::Vector2f(0.0f, -speed*deltaTime));
		gun.setPosition(body.getPosition() - sf::Vector2f(0.0f, bodySize.y / 2.0f));
		break;
	case sides::Down:
		this->direction = sides::Down;
		gun.setRotation(180.0f);
		body.setRotation(180.0f);
		body.move(sf::Vector2f(0.0f, speed*deltaTime));
		gun.setPosition(body.getPosition() + sf::Vector2f(0.0f, bodySize.y / 2.0f));
		break;
	case sides::Left:
		this->direction = sides::Left;
		gun.setRotation(-90.0f);
		body.setRotation(-90.0f);
		body.move(sf::Vector2f(-speed*deltaTime, 0.0f));
		gun.setPosition(body.getPosition() - sf::Vector2f(bodySize.x / 2.0f, 0.0f));
		break;
	case sides::Right:
		this->direction = sides::Right;
		gun.setRotation(90.0f);
		body.setRotation(90.0f);
		body.move(sf::Vector2f(speed*deltaTime, 0.0f));
		gun.setPosition(body.getPosition() + sf::Vector2f(bodySize.x / 2.0f, 0.0f));
	}
}

void Tank::Fire()
{
	if (cooldown.getElapsedTime().asSeconds() >= cooldownTime)
	{
		new Bullet(GetPosition(), GetDirection(),this->GetParty(),damage);
		cooldown.restart();
	}
}

void Tank::Update(const float &deltaTime)
{
	//body.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	//body.setFillColor(sf::Color::Black);
	//bodySize = sf::Vector2f(rand() % 100 + 5,rand() % 100 + 50);
	Fire();
}


void Tank::TakeDamage(const int& damage)
{
	hp -= damage;
	if (hp < 0) MakeDead();
}

bool Tank::CanMove(sides direction)
{
	float epsilon = 1.0f;
	for (Object* other : GetObjects())
	{
		if (other->GetPosition() == this->GetPosition() || other->GetTag()==Tags::Bullet) continue;
		switch (direction)
		{
		case sides::Up:
			if (this->GetPosition().y>other->GetPosition().y &&
				abs(this->GetPosition().y - other->GetPosition().y) - (this->GetSize().y + other->GetSize().y) / 2.0f <= epsilon &&
				abs(this->GetPosition().x - other->GetPosition().x) <= (this->GetSize().x + other->GetSize().x) / 2.0f) return false;
			break;
		case sides::Down:
			if (other->GetPosition().y > this->GetPosition().y &&
				abs(other->GetPosition().y - this->GetPosition().y) - (this->GetSize().y + other->GetSize().y) / 2.0f <= epsilon &&
				abs(this->GetPosition().x - other->GetPosition().x) <= (this->GetSize().x + other->GetSize().x) / 2.0f) return false;
			break;
		case sides::Left:
			if (this->GetPosition().x>other->GetPosition().x &&
				this->GetPosition().x - other->GetPosition().x - (this->GetSize().x + other->GetSize().x) / 2.0f <= epsilon &&
				abs(this->GetPosition().y - other->GetPosition().y) <= (this->GetSize().y + other->GetSize().y) / 2.0f) return false;
			break;
		case sides::Right:
			if (other->GetPosition().x>this->GetPosition().x &&
				other->GetPosition().x - this->GetPosition().x - (this->GetSize().x + other->GetSize().x) / 2.0f <= epsilon &&
				abs(this->GetPosition().y - other->GetPosition().y) <= (this->GetSize().y + other->GetSize().y) / 2.0f) return false;
			break;
		}
	}
	return true;
}


