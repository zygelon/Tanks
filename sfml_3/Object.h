#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include <forward_list>

enum class sides { Up, Down, Left, Right };
enum class Tags{Tank,Brick,Bullet};
enum class Parties{FPlayer, Evil, Neutral,SPlayer};

class Object
{
public:
	friend bool IsCollision(const Object&,const Object&) ;
	//friend class Global;
	Object(Tags tag,Parties party=Parties::Neutral);
	virtual ~Object();
	Tags GetTag() { return tag; }
	bool IsDead() { return isDead; }
	static const std::forward_list<Object*>& GetObjects() { return objects; }
	Parties GetParty() { return party; }
	static void DestroyDeadObjects();
	//static void UpdateObjectsCollision();
	virtual const sf::Vector2f& GetSize() const = 0;
	virtual const sf::Vector2f& GetPosition() const = 0;
	virtual void Update(const float &deltaTime) = 0;
	virtual void Draw(sf::RenderWindow &window) = 0;
	void MakeDead() { if(!isDead) isDead = true; }

private:
	Parties party;
	static  std::forward_list<Object*>objects;
	Tags tag;
	bool isDead = false;

protected:
};

