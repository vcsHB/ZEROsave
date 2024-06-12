#include "GameScene.h"

//bool GameScene::Init()
//{
//	return false;
//}

bool GameScene::Init()
{
	return false;
}

SceneState GameScene::Update() {

	cout << "Game Scene Updated" << endl;
	return { false, true, SceneTypeEnum::Title };
};

void GameScene::Render() {

}
