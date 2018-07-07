#include "CreatureTile.h"
#include "ofMain.h"
#include "../systems/Fastrand.h"

CreatureTile::CreatureTile(int tileX, int tileY) :
	x(tileX),
	y(tileY),
	color(randalgorithms::fastrand() % 256, randalgorithms::fastrand() % 256, randalgorithms::fastrand() % 256)
{
}

void CreatureTile::runTile()
{
	if (color.r > 0)
		color.r--;
	if (color.g > 0)
		color.g--;
	if (color.b < 255)
		color.b++;
}

void CreatureTile::drawTile()
{
	ofSetRectMode(OF_RECTMODE_CORNER);
	ofSetColor(color);
	ofRect(x * ITile::CELL_WIDTH, y * ITile::CELL_HEIGHT, ITile::CELL_WIDTH, ITile::CELL_HEIGHT);
}

//Getters
int CreatureTile::getX()
{
	return x;
}

int CreatureTile::getY()
{
	return y;
}

CreatureTile::~CreatureTile()
{

}