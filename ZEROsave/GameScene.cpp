#include "GameScene.h"



bool GameScene::Init()
{
	system("cls");	

	SetCursorVisual(false, 40);

	// 테스트 영역
	std::string mapTest[10] = {
	"2222222222",
	"2111112112",
	"2222211112",
	"2222212222",
	"3222212222",
	"3211111112",
	"3212222212",
	"3212222212",
	"3111111112",
	"3222222222"
	};
	_map = new Map();
	_map->startPosition = { 2,2 };
	// 테스트 영역
	_player = new Player();
	_player->Initialize();
	_map->Initialize(10, mapTest);
	_player->position = _map->startPosition;
	return true;

}


void GameScene::InitObjects()
{


}

SceneState GameScene::Update() 
{
	MovePlayer();
	Sleep(100);
	return { false, false, SceneTypeEnum::Title };
}

void GameScene::MovePlayer()
{
	// 인풋 받아와서 이동코드 작성
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		
		--_player->position.y;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		++_player->position.y;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		_player->position.x -= 2;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		_player->position.x += 2;
	}

	GotoPos(5, 13);
	cout << a++;
}

void GameScene::Render() {

	
	RenderMap();
	RenderPlayer();

}

void GameScene::RenderMap() {
	
	GotoPos(1, 0);
	for (int i = 0; i < _map->MapHeight; i++)
	{
		for (int j = 0; j < _map->MapWidth; j++)
		{
			SetColor((int)_map->GetTile(i, j).tileColor, (int)_map->GetTile(i, j).backgroundColor);
			cout << _map->GetTileVisual({i, j});
		}
		
		GotoPos(1, i+1);
	}
}

void GameScene::RenderObjects()
{
}

void GameScene::RenderPlayer() {
	Position playerPos = _player->position;
	GotoPos(playerPos.x+3, playerPos.y);
	SetColor((int)_player->objectColor);
	cout << _player->objectIcon;
	GotoPos(5, 13);
	cout << _player->position.x << ", " << _player->position.y;
}
