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
#include "UIRenderer.h"
#include "ObjectManager.h"
#include "console.h"

class UIRenderer;
class Map;
class ObjectManager;

class GameScene : public GameLogic
{
private :
	WindowManager* _windowManager = nullptr;
	UIRenderer* _uiRenderer = nullptr;
	ObjectManager* _objectManager = nullptr;
	Map* _map = nullptr;
	
	Player* _player = nullptr;
	
	int xOrigin = 0;
	int yOrigin = 0;

	COORD _windowSize;

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

