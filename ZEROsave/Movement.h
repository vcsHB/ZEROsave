#pragma once
#include "Object.h"
#include "Agent.h"

class Movement
{
private:
	class Agent* _owner;

public:

	Movement(Agent* agent) {
		_owner = agent;
	}

	void MoveTo(Position targetPos);

};