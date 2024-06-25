#pragma once
#include "Agent.h"

class Agent;

class Player : public Agent
{
public :

	void TakeDamage(int amount) override;

	void Initialize() override;

};

