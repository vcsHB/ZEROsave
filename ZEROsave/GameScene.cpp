#include "GameScene.h"



bool GameScene::Init()
{
	system("cls");	

	SetCursorVisual(false, 40);
	std::string mapTest[10] = {
	"01111111110",
	"01111111110",
	"01111111110",
	"01111111110",
	"01111111110",
	"01122222110",
	"00000000000",
	"00000000000",
	"00000000000",
	"00000000000"
	};
	_map = new Map();
	_map->Initialize(10, mapTest);

	return true;
}

SceneState GameScene::Update() 
{
	return { false, false, SceneTypeEnum::Title };
};

void GameScene::Render() {

	GotoPos(0, 0);
	RenderMap();

}

void GameScene::RenderMap() {
	
	for (int i = 0; i < _map->MapHeight; i++)
	{
		for (int j = 0; j < _map->MapWidth; j++)
		{
			cout <<_map->GetTileVisual({i, j});
		}
		
		GotoPos(0, i);
	}
}
