#include "ObjectManager.h"

ObjectManager* ObjectManager::_instance = nullptr;
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
	for (int i = 0; i < _objectList.size(); i++)
	{
		_objectList[i]->Update();
	}
}

void ObjectManager::DeleteObject(Object* object)
{
	auto it = std::find(_objectList.begin(), _objectList.end(), object);

	// 찾았으면
	if (it != _objectList.end()) {
		// 메모리 해제
		delete* it;
		// 벡터에서 포인터 제거
		_objectList.erase(it);
	}
}

std::vector<Object*> ObjectManager::GetObjects()
{
	return _objectList;
}

Object* ObjectManager::FindObject(Position position)
{
	for (Object* obj : _objectList)
	{
		if (obj->position == position) {
			return obj;
		}
	}
	return nullptr;
}
