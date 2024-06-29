#pragma once
#include <string>
#include "Define.h"
#include "Object.h"
#include "console.h"

const std::string TILE_SET[] = { "  ", "  ", "■", "▦", "▦"};
const COLOR TILE_COLORSET[] =	{ COLOR::GRAY, COLOR::LIGHT_GREEN, COLOR::BLACK, COLOR::LIGHT_RED,COLOR::LIGHT_GREEN };
const COLOR TILE_BGCOLORSET[] = { COLOR::GRAY, COLOR::BLACK, COLOR::GREEN, COLOR::RED, COLOR::BLACK };

enum class TileTypeEnum {
	None = 0,
	Road,
	Wall,

	Barrier

};

typedef struct MapTile {
	TileTypeEnum tileType;
	Position position;
	COLOR tileColor;
	COLOR backgroundColor;
	bool isColorSet = false;

	MapTile() {
		tileType = TileTypeEnum::None;
		position = { 0,0 };
		tileColor = COLOR::LIGHT_GREEN;
		backgroundColor = COLOR::BLACK;
	}

	MapTile(TileTypeEnum type, Position pos) {
		tileType = type;
		position = pos;
		tileColor = COLOR::LIGHT_GREEN;
		backgroundColor = COLOR::BLACK;
	}

	MapTile(TileTypeEnum type, Position pos, COLOR color, COLOR bgColor) {
		tileType = type;
		position = pos;
		tileColor = color;
		backgroundColor = bgColor;
	}

}MapTile;

class Map
{
private :
	static Map* _instance;
private :
	Map() {

	}
public:
	static Map* GetInstance()
	{
		if (_instance == nullptr)
			_instance = new Map();
		return _instance;
	}

	static void DestroyInstance()
	{
		if (_instance != nullptr) {
			delete _instance;
			_instance = nullptr;
			//SAFE_DELETE();
			/*if (instance != nullptr)
			{
				delete instance;
				instance = nullptr;
			}*/
		}
	}

	int MapWidth = 0;
	int MapHeight = 0;
	Position startPosition = {};

	// 맵 타일들을 관리함
	MapTile** mapTiles;

	void Initialize(int size, std::string* mapText);

	MapTile GetTile(int XPos, int YPos);

	MapTile GetTile(Position position);
	
	std::string GetTileVisual(Position position);

	void Destory();

};