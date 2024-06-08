#pragma once
#include "Object.h"

class Agent : public DamageableObject {

public:
	Movement MovementCompo;

	Agent() {
		//MovementCompo = new Movement(this);
	}


};

