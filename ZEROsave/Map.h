#pragma once
#include "Object.h"
const char TILE_SET[] = { ' ', '□', '■', '▦', 'ㅁ'};

enum class TileTypeEnum {
	None,
	Road,
	Wall,

	Barrier

};

typedef struct MapTile {
	TileTypeEnum tileType;
	Position position;

	MapTile() {
		tileType = TileTypeEnum::None;
		position = { 0,0 };
	}

	MapTile(TileTypeEnum type, Position pos) {
		tileType = type;
		position = pos;
	}

};

class Map
{
public:
	int MapWidth;
	int MapHeight;

	// 맵 타일들을 관리함
	MapTile** maptiles;

	void Initialize(int size, char** mapText);

	MapTile GetTile(int XPos, int YPos);
	
	char GetTileVisual(Position position);

	void Destory();
};

