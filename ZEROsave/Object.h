#pragma once
#include "console.h"
#include <string>

typedef struct Position
{
	int x;
	int y;

	//Position(int _x, int _y) { x = _x, y = _y; }
};

class Health {
private :
	int _currentHP;
public:
	
	int maxHP;

	void TakeDamage(int amount);

	void RestoreHealth(int amount);

	int GetCurrentHP() { return _currentHP; }


};



class Object
{
public :
	std::string objectIcon;
	COLOR objectColor;

	Position position;
	// �̵��� ���� ��ġ ������ ���� ����
	Position newPosition;

	virtual void Initialize() = 0;

};



