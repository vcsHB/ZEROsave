#pragma once
#include "Agent.h"

class Player : public Agent
{
public :
	float attackCooltime = 0;

	void TakeDamage(int amount) override;

	void Initialize() override;

};

