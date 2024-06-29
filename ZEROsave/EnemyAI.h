#pragma once
#include <functional>
#include "Agent.h"
#include "Map.h"
#include "Collider.h"

class Agent;
class Map;
class Collider;

class EnemyAI
{
private :
	Agent* _owner;
	Map* _map;
	Collider* _collider;
	float _currentMovecooldown;
	float _moveCooltime = 1;
public :

	void Initialize(Agent* owner);

	void CheckCollision();

	void Move();

	void MoveTurn(Collider* hit);
	void MoveTurnForce();

	void Update();
};

