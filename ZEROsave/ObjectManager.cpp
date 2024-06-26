#include "ObjectManager.h"

//void ObjectManager::SpawnObject(FieldObject* object)
//{
//	_objectList.push_back(object);
//}
//
//void ObjectManager::SpawnAgent(Agent* agent)
//{
//	_agentList.push_back(agent);
//}

void ObjectManager::GenerateObject(Object* object)
{
	_objectList.push_back(object);


}

void ObjectManager::Update()
{
}

std::vector<Object*> ObjectManager::GetObjects()
{
	return _objectList;
}
