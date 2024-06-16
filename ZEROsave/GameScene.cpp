#include "GameScene.h"
#include "console.h"


bool GameScene::Init()
{
	system("cls");
	SetCursorVisual(false, 40);
	return true;
}

SceneState GameScene::Update() 
{
	return { false, false, SceneTypeEnum::Title };
};

void GameScene::Render() {

	GotoPos(0, 0);
	cout << "ming";

}

void GameScene::RenderMap() {
	for (int i = 0; i < _map->MapHeight; i++)
	{
		for (int j = 0; j < _map->MapWidth; j++)
		{

		}
	}
}
