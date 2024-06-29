#pragma once
#include "Map.h"
#include "Object.h"
#include "Player.h"
#include "WindowManager.h"
#include "console.h"
const std::string GAUGE_TILESET = { "  " };

class Map;

class UIRenderer
{
private :
	Player *_player;
	Map* _map;
	WindowManager* _windowManager;

public:
	void Initialize(Player* player, WindowManager* windowManager);

	void Render();

};