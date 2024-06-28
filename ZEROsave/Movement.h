#pragma once
#include "Object.h"

class Movement
{
private:
	class Object* _owner;

public:

	Movement(Object* object) {
		_owner = object;
	}

	void MoveTo(Position targetPos);

};