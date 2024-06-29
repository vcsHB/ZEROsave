#pragma once
#include "Object.h"

class DamageableObject : public Object {

public:
	Health* HealthCompo;

	DamageableObject() {
		HealthCompo = new Health();
	}

	virtual void TakeDamage(int amount) = 0;
};


