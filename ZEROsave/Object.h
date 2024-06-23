#pragma once
#include "console.h"
#include <string>

typedef struct Position
{
	int x;
	int y;

	//Position(int _x, int _y) { x = _x, y = _y; }
	void ClampX(int min, int max) {
		if (x > max) x = max;
		if (x < min) x = min;
	}
	void ClampY(int min, int max) {
		if (y > max) y = max;
		if (y < min) y = min;
	}
};

class Health {
private :
	int _currentHP;
public:
	
	int maxHP;

	void Initialize(int amount);

	void TakeDamage(int amount);

	void RestoreHealth(int amount);

	int GetCurrentHP() { return _currentHP; }


};



class Object
{
public :
	std::string objectIcon;
	COLOR objectColor;
	COLOR objectBackgroundColor;

	Position position;
	// 이동에 따른 위치 보정을 위한 변수
	Position newPosition;

	virtual void Initialize() = 0;

};



