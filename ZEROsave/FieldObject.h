#pragma once
#include "Object.h"
#include "Collider.h"
class FieldObject : public Object
{
private :
	Collider* _collider;
	
public:
	void Initialize() {
		_collider = new Collider(this, ColliderType::Object, ColliderType::Player);
	}

};

