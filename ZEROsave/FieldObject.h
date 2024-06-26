#pragma once
#include "Object.h"
#include "DamageableObject.h"

class FieldObject : public DamageableObject
{
protected :
	class Collider* _collider;
	
public:
	void Initialize();

	virtual void Destroy(bool value) = 0;
	
	void TakeDamage(int amount) override;


};

