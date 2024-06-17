#pragma once
#include <iostream>
#include <string>
#include "Object.h"
const std::string TILE_SET[] = { "��", "��", "��", "��", "��"};

enum class TileTypeEnum {
	None = 0,
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

	void Initialize(int size, std::string* mapText);

	MapTile GetTile(int XPos, int YPos);
	
	std::string GetTileVisual(Position position);

	void Destory();
};

