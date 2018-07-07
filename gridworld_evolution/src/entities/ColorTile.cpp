#include "ColorTile.h"
#include "ofMain.h"
#include "../systems/Fastrand.h"

ColorTile::ColorTile(int tileX, int tileY) :
	x(tileX),
	y(tileY),
	color(rand() % 20, (randalgorithms::fastrand() % 50) + 100, 255)
{
}

ColorTile::ColorTile(int tileX, int tileY, ofColor col) :
	x(tileX),
	y(tileY),
	color(col)
{
}

void ColorTile::runTile()
{
	//color.r = ofClamp((int)color.r + ofRandom(-1.0f, 2.0f), 0, 255);
	//color.g = ofClamp((int)color.g + ofRandom(-1.0f, 2.0f), 0, 255);
	//color.b = ofClamp((int)color.b + ofRandom(-1.0f, 2.0f), 0, 255);
}

void ColorTile::drawTile()
{
	ofSetRectMode(OF_RECTMODE_CORNER);
	ofSetColor(color);
	ofRect(x * ITile::CELL_WIDTH, y * ITile::CELL_HEIGHT, ITile::CELL_WIDTH, ITile::CELL_HEIGHT);
}

//Getters
int ColorTile::getX()
{
	return x;
}

int ColorTile::getY()
{
	return y;
}

ColorTile::~ColorTile()
{
}