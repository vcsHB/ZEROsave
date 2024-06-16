#pragma once
#include "Object.h"
const char TILE_SET[] = { ' ', '��', '��', '��', '��'};

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

	// �� Ÿ�ϵ��� ������
	MapTile** maptiles;

	void Initialize(int size, char** mapText);

	MapTile GetTile(int XPos, int YPos);
	
	char GetTileVisual(Position position);

	void Destory();
};

