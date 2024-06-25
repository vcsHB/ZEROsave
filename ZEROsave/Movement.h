#pragma once
#include "Object.h"
#include "Agent.h"

class Agent;

class Movement
{
private:
	Agent* _owner;

public:

	Movement(Agent* agent) {
		_owner = agent;
	}

	void MoveTo(Position targetPos);

};