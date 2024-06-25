#pragma once
#include "DamageableObject.h"
#include "Movement.h"
#include "Stat.h"
#include "Collider.h"

class Movement;
class Stat;
class Collider;

class Agent : public DamageableObject 
{
public:
	Movement* MovementCompo = nullptr;
	Stat* Status = nullptr;
	Collider* collider = nullptr;

	Agent() {
		
	}

	~Agent() {
		delete MovementCompo;
		delete Status;
		delete collider;

	}
};