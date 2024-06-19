#include "GameScene.h"
#include <fstream>


bool GameScene::Init()
{
	system("title ZERO Save | mode con cols=80 lines=40");
	system("cls");	

	SetCursorVisual(false, 1);
	LockResize();
	SetFontsize(FW_BOLD, 20, 20);

	
	// 테스트 영역
	/*_map = new Map();
	std::string mapTest[15] = {
	"333333333333311",
	"311111211333311",
	"3222211113",
	"3224414223",
	"3244414223",
	"3211111113",
	"3212222213",
	"3212222213",
	"3111111113",
	"3333333333",
	"3333333333",
	"3333333333",
	"3333333333",
	"3333333333",
	"3333333333"
	};
	_map->startPosition = { 2,2 };
	_map->Initialize(15, mapTest);*/

	// 테스트 영역

	// 맵 로드
	InitMapData();
	cout << "맵 로드";
	//InitMapData();
	

	_player = new Player();
	_player->Initialize();
	_player->position = _map->startPosition;
	return true;

}


void GameScene::InitObjects()
{


}

void GameScene::InitMapData()
{
	if (_map != nullptr)
		delete _map;

	std::fstream readMap("StageFiles/stage.txt");

	if (!readMap.is_open())
		return;
	// 맵 생성 ======
	_map = new Map();
	std::string bufferStr;
	std::getline(readMap, bufferStr);
	int size = stoi(bufferStr); // 사이즈 지정
	_map->MapHeight = size;
	_map->MapWidth = size;
	//cout << "size : " << size << endl;
	// 시작 위치 =======

	std::getline(readMap, bufferStr);
	int positionBufferX;
	positionBufferX = stoi(bufferStr);
	int positionBufferY;
	std::getline(readMap, bufferStr);
	
	positionBufferY = stoi(bufferStr);
	_map->startPosition = { positionBufferX, positionBufferY };
	//cout << positionBufferX << ", " << positionBufferY << endl;

	// 맵 정의 =========
	std::string* mapString = new std::string[size];
	for (int i = 0; i < size; i++)
	{
		
		std::getline(readMap, bufferStr);
		if (readMap.fail()) {
			std::cout << "파일 에러";
		}
		mapString[i] = bufferStr;
		

	}
	readMap.close();
	_map->Initialize(size, mapString);


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
}

void GameScene::Render() {

	COORD coord = GetConsoleResolution();
	xOrigin = coord.X / 2 - _map->MapWidth;
	yOrigin = coord.Y / 2 - _map->MapHeight;
	cout << xOrigin << ", " << yOrigin;
	RenderMap();
	RenderPlayer();

}

void GameScene::RenderMap() {
	
	
	GotoPos(xOrigin, yOrigin);
	for (int i = 0; i < _map->MapHeight; i++)
	{
		for (int j = 0; j < _map->MapWidth; j++)
		{
			SetColor((int)_map->GetTile(i, j).tileColor, (int)_map->GetTile(i, j).backgroundColor);
			cout << _map->GetTileVisual({i, j});
		}
		
		GotoPos(xOrigin, yOrigin + i + 1);
	}
}

void GameScene::RenderPlayer() {
	Position playerPos = _player->position;
	GotoPos(xOrigin + playerPos.x + 2, yOrigin + playerPos.y);
	SetColor((int)_player->objectColor, (int)_player->objectBackgroundColor);
	cout << _player->objectIcon;
	//GotoPos(5, 13);
	//cout << _player->position.x << ", " << _player->position.y;
}


void GameScene::RenderObjects()
{
}

void GameScene::RenderUI() {
	int hp = _player->HealthCompo->GetCurrentHP();
	int maxHp = _player->HealthCompo->maxHP;

	
}

