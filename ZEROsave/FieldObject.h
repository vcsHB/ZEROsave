#pragma once
#include "Object.h"
#include "DamageableObject.h"

class FieldObject : public DamageableObject
{
private :
	class Collider* _collider;
	
public:
	void Initialize();

	void Destroy();
	

};

