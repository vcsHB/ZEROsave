#pragma once
#include <string>
#include "console.h"

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


	void VectorAdd(Position direction) {
		x += direction.x;
		y += direction.y;

	}

	void VectorNormalizedAdd(Position direction) {

		direction.ClampX(-1, 1); 
		direction.ClampY(-1, 1);
		x += direction.x;
		y += direction.y;

	}

	Position operator+ (Position b) {
		return { x + b.x, y + b.y };
	}

	void operator+= (Position b) {
		x += b.x;
		y += b.y;
	}

	Position operator- (Position b) {
		return { x - b.x, y - b.y };
	}

	bool operator== (Position b) {
		return x == b.x && y == b.y;
	}

	
}Position;




class Object
{
public :
	std::string objectIcon = "  ";
	COLOR objectColor = COLOR::WHITE;
	COLOR objectBackgroundColor = COLOR::BLACK;

	Position position = {};
	// 이동에 따른 위치 보정을 위한 변수
	Position newPosition = {0, 0};
	Position lastVelocity = { 1,0 };

	virtual void Initialize() = 0;

	virtual void Update() = 0;

	~Object() {

	}
	bool operator== (Object* b) {
		return (position == b->position) && objectIcon == b->objectIcon;
	}

};



