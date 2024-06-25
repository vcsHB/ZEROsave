#include "EnemyAI.h"

void EnemyAI::Initialize(Agent* owner) 
{
	_owner = owner;
	_collider = _owner->collider;
}

void EnemyAI::CheckCollision()
{
	
}
