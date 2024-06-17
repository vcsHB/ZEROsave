#pragma once
#include "console.h"
#include <string>
#include "Object.h"
const std::string TILE_SET[] = { "▩", "□", "■", "▦", "ㅁ"};
const COLOR TILE_COLORSET[] = { COLOR::GRAY, COLOR::LIGHT_GREEN, COLOR::GREEN, COLOR::LIGHT_RED };

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

	MapTile() {
		tileType = TileTypeEnum::None;
		position = { 0,0 };
		tileColor = COLOR::LIGHT_GREEN;
	}

	MapTile(TileTypeEnum type, Position pos) {
		tileType = type;
		position = pos;
		tileColor = COLOR::LIGHT_GREEN;
	}

	MapTile(TileTypeEnum type, Position pos, COLOR color) {
		tileType = type;
		position = pos;
		tileColor = color;
	}

};

class Map
{
public:
	int MapWidth;
	int MapHeight;
	Position startPosition;

	// 맵 타일들을 관리함
	MapTile** maptiles;

	void Initialize(int size, std::string* mapText);

	MapTile GetTile(int XPos, int YPos);
	
	std::string GetTileVisual(Position position);

	void Destory();
};

