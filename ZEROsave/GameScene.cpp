#include "GameScene.h"
#include "Movement.h"



bool GameScene::Init()
{
	system("title ZERO Save | mode con cols=60 lines=30");
	system("cls");	
	//
	SetCursorVisual(false, 1);
	LockResize();  
	SetFontsize(FW_BOLD, 20, 20);

	_map = Map::GetInstance();
	_windowManager = new WindowManager();
	_uiRenderer = new UIRenderer();
	_objectManager = new ObjectManager();

	// 맵 로드
	InitStageData();


	_player = new Player();
	_player->HealthCompo->Initialize(10);

	_player->Initialize();
	_player->position = _map->startPosition;
	_player->newPosition = _map->startPosition;

	_uiRenderer->Initialize(_player, _windowManager);
	return true;
}




void GameScene::InitStageData()
{
	if (_map != nullptr)
		delete _map;

	std::fstream readMap("StageFiles/stage.txt");

	if (!readMap.is_open())
		return;
	// 맵 생성 ======
	_map = Map::GetInstance();
	std::string bufferStr;
	getline(readMap, bufferStr);
	int size = stoi(bufferStr); // 사이즈 지정
	_map->MapHeight = size;
	_map->MapWidth = size;
	//cout << "size : " << size << endl;
	// 시작 위치 =======

	int positionBufferX;
	int positionBufferY;
	getline(readMap, bufferStr);
	positionBufferX = stoi(bufferStr);
	getline(readMap, bufferStr);
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

	// 오브젝트 가져오기
	Enemy* testEnemy = new Enemy();
	testEnemy->Initialize();
	testEnemy->position = { 8, 10 };
	_objectManager->GenerateObject(testEnemy);

	//int _objectAmount;
	//std::getline(readMap, bufferStr);
	//_objectAmount = stoi(bufferStr);
	//// 
	//for (int i = 0; i < _objectAmount; i++)
	//{
	//	std::getline(readMap, bufferStr);
	//	
	//	std::getline(readMap, bufferStr);
	//	positionBufferX = stoi(bufferStr);
	//	std::getline(readMap, bufferStr);
	//	positionBufferY = stoi(bufferStr);
	//	Position pos = { positionBufferX, positionBufferY };
	//	

	//	
	//}

	readMap.close();
	_map->Initialize(size, mapString);

	SetColor((int)COLOR::LIGHT_RED);
	cout << "▶ MAP SIZE    <" << _map->MapWidth << " * " << _map->MapHeight << ">";

}

void GameScene::InitObjects()
{
	

}

SceneState GameScene::Update() 
{
	MovePlayer();
	UpdateWindow();
	return { false, false, SceneTypeEnum::Title };
}

void GameScene::MovePlayer()
{
	_player->newPosition = _player->position;
	// 인풋 받아와서 이동코드 작성
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		
		--_player->newPosition.y;
	}
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		++_player->newPosition.y;
	}
	else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		_player->newPosition.x--;
		//_player->newPosition.x -= 2;
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		//_player->newPosition.x += 2;
		_player->newPosition.x++;
	}
	_player->newPosition.ClampX(0, _map->MapWidth-1);
	_player->newPosition.ClampY(0, _map->MapHeight-1);
	MapTile tile = _map->GetTile(_player->newPosition);
	if ((int)tile.tileType != 1) {
		return;
	}

	_player->MovementCompo->MoveTo(_player->newPosition);
	Sleep(100);
}

void GameScene::ControlPlayer()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
		// 공격 구현 해야디


	}


}

void GameScene::UpdateWindow()
{
	_windowManager->UpdateWindow();
	
}

void GameScene::CheckGetItem()
{
	


}


void GameScene::Render() {

	_windowSize = GetConsoleResolution();
	_windowManager->windowSizeX = _windowSize.X;
	_windowManager->windowSizeY = _windowSize.Y;
	xOrigin = _windowSize.X / 2 - _map->MapWidth;
	yOrigin = _windowSize.Y / 2 - _map->MapHeight/2;
	//cout << xOrigin << ", " << yOrigin;
	RenderMap();
	RenderPlayer();
	RenderObjects();
	RenderUI();

}

void GameScene::RenderMap() 
{
	GotoPos(xOrigin, yOrigin);
	for (int i = 0; i < _map->MapHeight; i++)
	{
		for (int j = 0; j < _map->MapWidth; j++)
		{
			MapTile tile = _map->GetTile(j, i);
			SetColor((int)tile.tileColor, (int)tile.backgroundColor);
			cout << _map->GetTileVisual({j, i});
			//cout << (int)tile.tileType << " ";
		}
		
		GotoPos(xOrigin, yOrigin + i + 1);
	}
}

void GameScene::RenderPlayer() {
	Position playerPos = _player->position;
	GotoPos(xOrigin + playerPos.x * 2, yOrigin + playerPos.y);
	SetColor((int)_player->objectColor, (int)_player->objectBackgroundColor);
	cout << _player->objectIcon;
	
}


void GameScene::RenderObjects()
{
	vector<Object*> _objectList = _objectManager->GetObjects();
	for (Object* object : _objectList)
	{
		GotoPos(xOrigin + object->position.x * 2, yOrigin + object->position.y);
		SetColor((int)object->objectColor, (int)object->objectBackgroundColor);
		cout << object->objectIcon;
	}
}


void GameScene::RenderUI() 
{
	_uiRenderer->Render();
	

}



void GameScene::Exit()
{
	
	delete[] _map;
}


