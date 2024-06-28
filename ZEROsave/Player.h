#pragma once
#include <functional>
#include "Agent.h"

class Player : public Agent
{
public :
	float attackCooltime = 0;

	void TakeDamage(int amount) override;

	void Initialize() override;

	void HandleEnemyCollision(Collider* hit);

	void Update() override;
};

