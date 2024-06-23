#include "GameScene.h"


bool GameScene::Init()
{
	system("title ZERO Save | mode con cols=60 lines=30");
	system("cls");	
	//
	SetCursorVisual(false, 1);
	LockResize();  
	SetFontsize(FW_BOLD, 20, 20);

	
	_windowManager = new WindowManager();
	// �� �ε�
	InitMapData();

	_player = new Player();
	_player->HealthCompo->Initialize(10);

	_player->Initialize();
	_player->position = _map->startPosition;
	_player->newPosition = _map->startPosition;
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
	// �� ���� ======
	_map = new Map();
	std::string bufferStr;
	std::getline(readMap, bufferStr);
	int size = stoi(bufferStr); // ������ ����
	_map->MapHeight = size;
	_map->MapWidth = size;
	//cout << "size : " << size << endl;
	// ���� ��ġ =======

	int positionBufferX;
	std::getline(readMap, bufferStr);
	positionBufferX = stoi(bufferStr);

	int positionBufferY;
	std::getline(readMap, bufferStr);
	positionBufferY = stoi(bufferStr);
	_map->startPosition = { positionBufferX, positionBufferY };
	//cout << positionBufferX << ", " << positionBufferY << endl;

	// �� ���� =========
	std::string* mapString = new std::string[size];
	for (int i = 0; i < size; i++)
	{
		
		std::getline(readMap, bufferStr);
		if (readMap.fail()) {
			std::cout << "���� ����";
		}
		mapString[i] = bufferStr;
		

	}
	readMap.close();
	_map->Initialize(size, mapString);


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
	// ��ǲ �޾ƿͼ� �̵��ڵ� �ۼ�
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

void GameScene::UpdateWindow()
{
	_windowManager->UpdateWindow();
	
}


void GameScene::Render() {

	_windowSize = GetConsoleResolution();
	xOrigin = _windowSize.X / 2 - _map->MapWidth;
	yOrigin = _windowSize.Y / 2 - _map->MapHeight/2;
	cout << xOrigin << ", " << yOrigin;
	RenderMap();
	RenderPlayer();
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
	GotoPos(0, 1);
	cout << "��ġ: " << _player->position.x << ", " << _player->position.y;
	GotoPos(0, 2);
	cout << "�� ��ġ: " << _player->newPosition.x << ", " << _player->newPosition.y;
}


void GameScene::RenderObjects()
{
}


void GameScene::RenderUI() {
	GotoPos(_windowSize.X / 2, _windowSize.Y - 1);
	int hp = _player->HealthCompo->GetCurrentHP();
	int maxHp = _player->HealthCompo->maxHP;
	int fillAmount = (int)(((float)hp / maxHp) * 10);
	SetColor((int)COLOR::LIGHT_BLUE, (int)COLOR::BLUE);
	for (int i = 0; i < fillAmount; i++)
	{
		wcout << GAUGE_TILESET[0];
	}
	SetColor((int)COLOR::LIGHT_BLUE, (int)COLOR::BLACK);
	for (int i = 0; i < 10- fillAmount; i++)
	{
		wcout << GAUGE_TILESET[0];
	}
	SetColor();
}



void GameScene::Exit()
{
	
	delete[] _map;
}


