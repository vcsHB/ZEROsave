#pragma once
#include "Object.h"
#include "Player.h"
#include "Map.h"
#include "WindowManager.h"
#include "console.h"
const std::string GAUGE_TILESET = { "  " };


class UIRenderer
{
private :
	Player *_player;
	Map* _map;
	WindowManager* _windowManager;

public:
	void Initialize(Player* player, Map* map, WindowManager* windowManager);

	void Render();

};