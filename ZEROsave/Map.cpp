#include "Map.h"

void Map::Initialize(int size, char** mapText)
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
	MapWidth, MapHeight = size;
	maptiles = new MapTile*[size];
	for (int i = 0; i < MapHeight; i++)
	{
		maptiles[i] = new MapTile[size];
		for (int j = 0; j < MapWidth; j++)
		{
			maptiles[i] = new MapTile(
				(TileTypeEnum)mapText[i][j],
				{ 0,0 }
			);
		}
	}
}

MapTile Map::GetTile(int XPos, int YPos)
{
    return MapTile();
}

char Map::GetTileVisual(Position position)
{
	MapTile tile = GetTile(position.x, position.y);
	char result = TILE_SET[(int)tile.tileType];
	
	return result;

}
