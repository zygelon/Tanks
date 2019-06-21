#include "Object.h"

Object::Object(Parties party)
{
	//this->tag = tag;
	this->party=party;
	objects.push_front(this);
}

std::forward_list<Object*>Object::objects;

Object::~Object()
{
}

void Object::DestroyDeadObjects()
{
	for (auto i = objects.before_begin(); i != objects.end(); ++i)
	{
		decltype(i) next = i;
		++next;
		if (next == Object::GetObjects().end()) break;
		if ((*next)->IsDead())
		{
			delete next;
			objects.erase_after(i);
			continue;
		}
	}
}

bool IsCollision(const Object& a , const Object& b)  {
	float epsilon = 1.5f;
	if (abs(a.GetPosition().x - b.GetPosition().x)+epsilon <= (a.GetSize().x + b.GetSize().x) / 2.0f
		&& abs(a.GetPosition().y - b.GetPosition().y)+epsilon <= (a.GetSize().y + b.GetSize().y) / 2.0f) return true;
	else return false;
}
