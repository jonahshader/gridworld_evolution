#pragma once

/*
this is an interface that all game objects implement 
(because everything is a tile that exists in the world)
*/
class ITile
{
public:
	virtual void runTile() = 0;
	virtual void drawTile() = 0;

	virtual int getX() = 0;
	virtual int getY() = 0;

	static const int CELL_WIDTH = 32;
	static const int CELL_HEIGHT = 32;
};