#pragma once
#include <vector>
#include "Agent.h"
#include "Object.h"

enum class ObjectType{
	Item,

};

class ObjectManager
{
private:
	std::vector<Object> _objectList;
	std::vector<Agent> _agentList;

public:
	void SpawnObject();
	void SpawnAgent(Agent agent);

	void Update();

};

