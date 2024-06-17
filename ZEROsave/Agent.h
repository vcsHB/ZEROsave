#pragma once
#include "Stat.h"
#include "Object.h"
#include "DamageableObject.h"
#include "Movement.h"

class Agent : public DamageableObject {

public:
	class Movement* MovementCompo;
	class Stat* Status;

	/*Agent() {
		MovementCompo = new Movement(this);
		Status = new Stat();
	}*/

	/*virtual void Initialize() {

	}*/


};

