#pragma once
#include <functional>
#include "Agent.h"
#include "delegate.h"
#include "Map.h"

class Map;

class Player : public Agent
{
private:
	Map* _map;
	//ObjectManager* _objectManager;
	
	float _attackCooldown = 0;

public :
	float attackCooltime = 1;
	Delegate<bool> OnPlayerDieEvent;

	void TakeDamage(int amount) override;

	void Initialize() override;

	void HandleEnemyCollision(Collider* hit);

	void Update() override;

	void HandlePlayerDie(bool value);

	// Control
	void MoveControl();
	void AttackControl();
};

