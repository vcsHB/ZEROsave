#pragma once
#include "console.h"
#include <string>
#include "Object.h"
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

	MapTile GetTile(Position position);
	
	std::string GetTileVisual(Position position);

	void Destory();
};

