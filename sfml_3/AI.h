#pragma once
#include "Tank.h"
#include <cstdlib>
#include <ctime>

class AI : public Tank//������ �������� ����� ���� ��������� ���-�� ��� � ��������� ��������
{
public:
	AI();
	AI(sf::Vector2f);
	~AI();

	void Update(const float &deltaTime);//��������������� ������� ��� � �����
private:
	sf::Clock clock;//����������

	float r;//����� ��� ����� ��� �� ����� ��������  
	
	sides direction;//����������� �����
};

