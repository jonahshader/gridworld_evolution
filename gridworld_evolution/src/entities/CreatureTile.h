#pragma once
#include "ITile.h"
#include "ofMain.h"

/*
this is the creature class...
*/

class CreatureTile : public ITile
{
public:
	CreatureTile(int tileX, int tileY);
	CreatureTile(const CreatureTile&) = delete; //Can't clone creature tiles
	virtual ~CreatureTile();

	void runTile() override;
	void drawTile() override;

	int getX() override;
	int getY()override;

private:
	int x, y;
	ofColor color;
};