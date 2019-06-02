#include "Global.h"
#include "Tank.h"


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
				//Tags firTag = (*i)->GetTag(), secTag = (*j)->GetTag();
				if (dynamic_cast<Bullet*>(*i) != nullptr && dynamic_cast<Tank*>(*j) != nullptr) {
					swap(i, j);
					//swap(firTag, secTag);
				}

				if (dynamic_cast<Bullet*>(*i) != nullptr && dynamic_cast<Bullet*>(*j) != nullptr) {
					(*i)->MakeDead(); (*j)->MakeDead();
				}

				else if (dynamic_cast<Tank*>(*i) != nullptr && dynamic_cast<Bullet*>(*j)!=nullptr) {
					(*j)->MakeDead();
					if ((*i)->GetParty() != (*j)->GetParty()) dynamic_cast<Tank*>(*i)->TakeDamage(dynamic_cast<Bullet*>(*j)->GetDamage());
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
