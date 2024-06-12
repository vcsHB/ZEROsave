#pragma once
#include "Object.h"

enum class TileTypeEnum {
	None,
	Wall,

	Item_,
	Ming
};

struct MapTile {
	TileTypeEnum tileType;
	Position position;


};

class Map
{
public:
	int MapWidth;
	int MapHeight;

	// �� Ÿ�ϵ��� ������
	MapTile* maptiles;

	MapTile GetTile(int XPos, int YPos);
};

