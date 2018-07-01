#pragma once
#include "Tank.h"
#include <cstdlib>
#include <ctime>

class AI : public Tank//просто движется хуй знает куда случайное кол-во сек и постоянно стреляет
{
public:
	AI();
	AI(sf::Vector2f);
	~AI();
private:
	sf::Clock clock;//секундомер

	float r;//время как долго наш ИИ будет страдать хуйней 
	void Update(const float &deltaTime);//переопределение апдейта что в танке
	sides direction;//направление танка
};

