#include "GameScene.h"
#include "Movement.h"

bool GameScene::Init()
{
	system("title ZERO Save | mode con cols=60 lines=30");
	system("cls");	
	
	SetCursorVisual(false, 1);
	LockResize();  
	SetFontsize(FW_BOLD, 20, 20);

	_map = Map::GetInstance();
	_windowManager = new WindowManager();
	_uiRenderer = new UIRenderer();
	_objectManager = ObjectManager::GetInstance();
	_player = new Player();

	// 맵 로드
	InitStageData();


	_player->HealthCompo->Initialize(10);
	_objectManager->GenerateObject(_player);

	_player->Initialize();
	_player->position = _map->startPosition;
	_player->newPosition = _map->startPosition;
	_player->HealthCompo->OnDieEvent.Add(std::bind(&GameScene::HandlePlayerDie, this, std::placeholders::_1));

	_uiRenderer->Initialize(_player, _windowManager);
	return true;
}




void GameScene::InitStageData()
{
	if (_map != nullptr)
		delete _map;

	std::fstream readMap("StageFiles\\stage.txt");

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
	if (_isGameOver) return { false, true, SceneTypeEnum::Title };

	UpdateWindow();
	_objectManager->Update();
	Sleep(100);

	return { false, false, SceneTypeEnum::Title };
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
	std::vector<Object*> _objectList = _objectManager->GetObjects();
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

void GameScene::HandlePlayerDie(bool value)
{
	_isGameOver = value;
}


