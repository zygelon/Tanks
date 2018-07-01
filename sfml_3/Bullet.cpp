#include "Bullet.h"


Bullet::Bullet(sf::Vector2f position, sides direction,Parties party) : Object(Tags::Bullet,party)
{
	/*global = Global::Access();
	global->AddBullet(this);*/
	bullet.setSize(bulletSize);
	bullet.setOrigin(sf::Vector2f(bulletSize.x / 2.0f, bulletSize.y / 2.0f));
	bullet.setFillColor(sf::Color::White);

	this->direction = direction;
	switch (direction)
	{
	case sides::Up:
		position.y -= offset;
		break;
	case sides::Down:
		position.y += offset;
		break;
	case sides::Right:
		position.x += offset;
		break;
	case sides::Left:
		position.x -= offset;
		break;
	}
	bullet.setPosition(position);
}


Bullet::~Bullet()
{
}

void Bullet::Update(const float& deltaTime)
{
	//bullet.setRadius(rand() % 100 / 10.0f + 0.5f); ÝÒÎ ÌÎÆÅØÜ ÂÛÏÈËÈÒÜ
	/*if (IsOutOfRange()) {
		global->DeleteBullet(this);
		this->~Bullet();
		return;
	}*/
	if (IsOutOfRange())
		MakeDead();
	switch (direction)
	{
	case sides::Up:
		bullet.move(sf::Vector2f(0.0f, -deltaTime*speed));
		break;
	case sides::Down:
		bullet.move(sf::Vector2f(0.0f, deltaTime*speed));
		break;
	case sides::Left:
		bullet.move(sf::Vector2f(-deltaTime*speed,0.0f));
		break;
	case sides::Right:
		bullet.move(sf::Vector2f(deltaTime*speed,0.0f));
		break;
	}
}

bool Bullet::IsOutOfRange()
{
	if (bullet.getPosition().x<0.0f || bullet.getPosition().x>WINDOW_LENGTH || bullet.getPosition().y > WINDOW_HEIGHT || bullet.getPosition().y < 0.0f) return true;
	else return false;
}

/*bool Bullet::IsCollision(Bullet* bullet)
{
	float epsilon = this->GetSize().x / 2.0f;
	sf::Vector2f residualBulletPos = this->GetPosition() - bullet->GetPosition();
	//cout << this->GetRadius() + bullet->GetRadius() - sqrt(sumBulletPos.x*sumBulletPos.x + sumBulletPos.y + sumBulletPos.y) << endl;
	if (abs(this->GetSize()+bullet->GetSize())
		>= abs(residualBulletPos)+epsilon)
		return true;
	return false;
}*/

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(bullet);
}
