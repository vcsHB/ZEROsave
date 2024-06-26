#pragma once
#include "Agent.h"
#include "EnemyAI.h"

class Enemy : public Agent
{
private :
	EnemyAI* _enemyAI;

public:

	void TakeDamage(int amount) override;

	void Initialize() override;
};

