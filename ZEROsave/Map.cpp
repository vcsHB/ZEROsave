#include "Map.h"
Map* Map::_instance = nullptr;


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
	mapTiles = new MapTile*[size];
	for (int i = 0; i < MapHeight; i++)
	{
		mapTiles[i] = new MapTile[size];
		 //널문자 반영 해야되나?
		for (int j = 0; j < MapWidth; j++)
		{
			mapTiles[i][j] = MapTile(
				(TileTypeEnum)(mapText[i][j] - '0'),
				{ i, j }
			);
		}
	}   
}
 
MapTile Map::GetTile(int XPos, int YPos)
{
 	if (mapTiles == nullptr) return MapTile();
	MapTile tile = mapTiles[YPos][XPos];
	/*GotoPos(0, 20);
	cout << XPos << ", " << YPos << "를 찾는다";*/
	if (!tile.isColorSet) {

		tile.isColorSet = true;
		tile.tileColor = TILE_COLORSET[(int)tile.tileType];
		tile.backgroundColor = TILE_BGCOLORSET[(int)tile.tileType];
	}
	return tile;
}

MapTile Map::GetTile(Position position)
{	
	
	return GetTile(position.x, position.y);
}

std::string Map::GetTileVisual(Position position)
{
	MapTile tile = GetTile(position.x, position.y);
	std::string result = TILE_SET[(int)tile.tileType];
	
	return result;

}

void Map::Destory()
{
}
