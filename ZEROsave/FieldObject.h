#pragma once
#include "Object.h"
#include "Collider.h"
class FieldObject : public Object
{
private :
	class Collider* _collider;
	
public:
	void Initialize();

	void Destroy();
	

};

