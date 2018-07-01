#include "Global.h"

Global::Global(){
}

Global::~Global(){}

Global* Global::Access()
{
	static Global s;
	return &s;
}
void Global::Update()
{
	for (auto i = Object::GetObjects().begin(); i != Object::GetObjects().end(); ++i)
	{
		auto j = i;
		++j;
		for (; j != Object::GetObjects().end(); ++j)
		{
			if (IsCollision(**i, **j))
			{
				Tags firTag = (*i)->GetTag(), secTag = (*j)->GetTag();
				if (firTag == Tags::Bullet && secTag == Tags::Tank) {
					swap(i, j);
					swap(firTag, secTag);
				}

				if (firTag == Tags::Bullet && secTag == Tags::Bullet) {
					(*i)->MakeDead(); (*j)->MakeDead();
				}

				else if (firTag == Tags::Tank && secTag == Tags::Bullet) {
					(*j)->MakeDead();
					if ((*i)->GetParty() != (*j)->GetParty()) (*i)->MakeDead();
				}
			}
		}
	}
	Object::DestroyDeadObjects();
	float deltaTime = clock.restart().asSeconds();
	//if (rand() % 1000 == 2) cout << deltaTime << endl;
	if (deltaTime > 0.1) deltaTime = 0.1;
	for (auto i = Object::GetObjects().begin(); i != Object::GetObjects().end(); ++i)
		(*i)->Update(deltaTime);
}
void Global::Draw(sf::RenderWindow& window)
{
	for (auto i = Object::GetObjects().begin(); i != Object::GetObjects().end(); ++i)
		(*i)->Draw(window);
}
