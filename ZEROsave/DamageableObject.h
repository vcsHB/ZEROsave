#pragma once
#include "Object.h"
#include "Health.h"

class Health;

class DamageableObject : public Object 
{
public:
	Health* HealthCompo = nullptr;

	DamageableObject() {
		HealthCompo = new Health();
	}

	virtual void TakeDamage(int amount) = 0;
};


