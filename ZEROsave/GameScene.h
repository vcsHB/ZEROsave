#pragma once
#include "Define.h"
#include <string>
#include <vector>
#include "GameLogic.h"
#include "Object.h"
#include "Player.h"
#include "Map.h"

#include "console.h"

class GameScene : public GameLogic
{
private :
	Map* _map;
	std::vector<Object> _objectList;
	Player* _player;
	int a = 0;
public:

	virtual bool Init() override;

	void InitObjects();

	virtual SceneState Update() override;

	void MovePlayer();


	virtual void Render() override;


	void RenderMap();
	void RenderPlayer();
	void RenderObjects();
	void RenderUI();


};

