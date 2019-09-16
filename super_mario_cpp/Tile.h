#pragma once
enum ETile {
	NONE,
	TILE_FLOOR,
	TILE_HOVER,
	TILE_POWER_UP,
	TOTAL_TILES
};

class Tile
{

public: 

private:
	ETile TileType;
	int mPositionX;
	int mPositionY;
	int mWidth;
	int mHeight;


};

