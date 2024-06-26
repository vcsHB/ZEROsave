#pragma once
#include "Object.h"
#include "DamageableObject.h"

class FieldObject : public DamageableObject
{
protected :
	class Collider* _collider;
	
public:
	virtual void Initialize();

	virtual void Destroy() = 0;
	
	void TakeDamage(int amount) override;


};

