#include "Map.h"

void Map::Initialize(int size, std::string* mapText)
{
	/*
	 * j j j j j j j
	 * i
	 * i
	 * i
	 * i
	 * i
	 * i
	 * 
	 */
	MapWidth = size;
	MapHeight = size;
	maptiles = new MapTile*[size];
	for (int i = 0; i < MapHeight; i++)
	{
		maptiles[i] = new MapTile[size];
		for (int j = 0; j < MapWidth; j++)
		{
			maptiles[i][j] = MapTile(
				(TileTypeEnum)(mapText[i][j]-48),
				{ i, j }
			);
		}
	}
}

MapTile Map::GetTile(int XPos, int YPos)
{
	MapTile tile = maptiles[XPos][YPos];
	if (!tile.isColorSet) {

		tile.isColorSet = true;
		tile.tileColor = TILE_COLORSET[(int)tile.tileType];
		tile.backgroundColor = TILE_BGCOLORSET[(int)tile.tileType];
	}
	return tile;
}

std::string Map::GetTileVisual(Position position)
{
	MapTile tile = GetTile(position.x, position.y);
	std::string result = TILE_SET[(int)tile.tileType];
	
	return result;

}
