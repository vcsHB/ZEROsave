#include "Movement.h"

void Movement::MoveTo(Position targetPos)
{
	_owner->position = targetPos;
}
