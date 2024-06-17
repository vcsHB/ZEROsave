#pragma once
#include "Stat.h"
#include "Object.h"

class Agent : public DamageableObject {

public:
	class Movement* MovementCompo;
	class Stat* Status;

	Agent() {
		MovementCompo = new Movement(this);
		Status = new Stat();
	}

	void Initialize() {

	}


};

