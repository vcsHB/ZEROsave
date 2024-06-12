#pragma once
#include "Object.h"

class Agent : public DamageableObject {

public:
	class Movement* MovementCompo;

	Agent() {
		MovementCompo = new Movement(this);
	}


};

