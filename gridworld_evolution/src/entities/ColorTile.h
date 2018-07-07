#pragma once
#include "ITile.h"
#include "ofMain.h"

/*
This is a immobile tile with a color
*/

class ColorTile : public ITile
{
public:
	ColorTile(int tileX, int tileY);
	ColorTile(int tileX, int tileY, ofColor col);
	ColorTile(const ColorTile&) = delete;
	virtual ~ColorTile();

	void runTile() override;
	void drawTile() override;

	int getX() override;
	int getY() override;

private:
	int x, y;
	ofColor color;
};