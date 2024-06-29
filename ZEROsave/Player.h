#pragma once
#include <functional>
#include "Agent.h"
#include "delegate.h"

class Player : public Agent
{

	
public :
	float attackCooltime = 0;
	Delegate<bool> OnPlayerDieEvent;

	void TakeDamage(int amount) override;

	void Initialize() override;

	void HandleEnemyCollision(Collider* hit);

	void Update() override;

	void HandlePlayerDie(bool value);
};

