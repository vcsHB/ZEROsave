#pragma once
#include "Agent.h"

class Player : public Agent
{
public :

	void TakeDamage(int amount) override;

	void Initialize() override;

};

