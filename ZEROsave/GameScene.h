#pragma once
#include "Define.h"
#include <string>
#include <vector>
#include <fstream>
#include "GameLogic.h"
#include "Object.h"
#include "Player.h"
#include "Map.h"
#include "WindowManager.h"

#include "console.h"

class GameScene : public GameLogic
{
private :
	WindowManager* _windowManager;
	Map* _map;
	std::vector<Object> _objectList;
	Player* _player;
	
	int xOrigin = 0;
	int yOrigin = 0;

public:


	virtual bool Init() override;

	void InitMapData();
	void InitObjects();

	virtual SceneState Update() override;

	void MovePlayer();
	void UpdateWindow();


	virtual void Render() override;


	void RenderMap();
	void RenderPlayer();
	void RenderObjects();
	void RenderUI();
	
	virtual void Exit() override;

};

