#pragma once
#include "Stat.h"
#include "Object.h"
#include "DamageableObject.h"
#include "Movement.h"
#include "Collider.h"

class Agent : public DamageableObject {

public:
	class Movement* MovementCompo;
	class Stat* Status;
	class Collider* collider;

	

	/*virtual void Initialize() {

	}*/


};

