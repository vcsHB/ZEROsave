#include "GameScene.h"



bool GameScene::Init()
{
	system("cls");	

	SetCursorVisual(false, 40);
	std::string mapTest[10] = {
	"1111111111",
	"1222222221",
	"1111111121",
	"1111111121",
	"1111112221",
	"1112222121",
	"1000022021",
	"1000020021",
	"1222222221",
	"1111111111"
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

	
	RenderMap();

}

void GameScene::RenderMap() {
	
	GotoPos(1, 0);
	for (int i = 0; i < _map->MapHeight; i++)
	{
		for (int j = 0; j < _map->MapWidth; j++)
		{
			cout << _map->GetTileVisual({i, j});
		}
		
		GotoPos(1, i+1);
	}
}
