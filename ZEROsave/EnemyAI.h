#pragma once
#include "Agent.h"
#include "Collider.h"

class Agent;
class Collider;

class EnemyAI
{
private :
	Agent* _owner;
	Collider* _collider;

public :

	void Initialize(Agent* owner);

	void CheckCollision();

	void Move();

	void MoveTurn();
};

