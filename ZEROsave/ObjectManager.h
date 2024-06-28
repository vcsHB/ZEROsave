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
	static ObjectManager* _instance;

	ObjectManager() {

	}

	std::vector<Object*> _objectList;

public:
	static ObjectManager* GetInstance()
	{
		if (_instance == nullptr)
			_instance = new ObjectManager();
		return _instance;
	}

	static void DestroyInstance()
	{
		if (_instance != nullptr) {
			delete _instance;
			_instance = nullptr;
			
		}
	}


	void GenerateObject(Object* object);
	
	void Update();


	std::vector<Object*> GetObjects();

	Object* FindObject(Position position);
};

