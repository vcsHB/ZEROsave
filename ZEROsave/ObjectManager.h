#pragma once
#include <vector>
#include "Agent.h"
#include "Object.h"
#include "FieldObject.h"

class FieldObject;
class Agent;

enum class ObjectType{
	Item,
	Barrier
};

class ObjectManager
{
private:
	std::vector<FieldObject*> _objectList;
	std::vector<Agent*> _agentList;

public:
	void SpawnObject(FieldObject* object);
	void SpawnAgent(Agent* agent);

	void Update();

};

