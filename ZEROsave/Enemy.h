#pragma once
#include "Agent.h"

class Enemy : public Agent
{


	void TakeDamage(int amount) override;

	void Initialize() override;
};

