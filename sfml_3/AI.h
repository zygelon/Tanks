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
private:
	sf::Clock clock;//����������

	float r;//����� ��� ����� ��� �� ����� ��������  
	void Update(const float &deltaTime);//��������������� ������� ��� � �����
	sides direction;//����������� �����
};

