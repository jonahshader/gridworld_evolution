#include "World.h"
#include "../entities/ColorTile.h"
#include "../entities/CreatureTile.h"
#include "Fastrand.h"

World::World(int width, int height) :
	worldWidth(width),
	worldHeight(height),
	worldTime(0)
{
	for (int y = 0; y < height; y++)
	{
		std::vector<ITile*> column;
		for (int x = 0; x < width; x++)
		{
			column.push_back(new ColorTile(x, y));
		}
		backgroundGrid.push_back(column);
	}

	for (int y = 0; y < height; y++)
	{
		std::vector<CreatureTile*> column;
		for (int x = 0; x < width; x++)
		{
			column.push_back(nullptr); //Fill the creature grid with a bunch of nullptrs to start off with
		}
		creatureGrid.push_back(column);
	}
}

void World::runWorld()
{
	//TEMP: add a creature randomly
	//if (rand() % 10 == 0)
	//{
	//	setCreatureTile(new CreatureTile(rand() % worldWidth, rand() % worldHeight));
	//}
	for (int i = 0; i < 2; i++)
	{
		setCreatureTile(new CreatureTile(randalgorithms::fastrand() % worldWidth, randalgorithms::fastrand() % worldHeight));
	}

	//Run all runnable background tiles
	for (ITile* tile : backgroundTiles)
	{
		tile->runTile();
	}

	//Run all creatures
	for (CreatureTile* creatureTile : creatures)
	{
		creatureTile->runTile();
	}

	worldTime++;
}

void World::drawWorld()
{
	//Draw every background tile (because none will be nullptr)
	for (std::vector<ITile*>& tileStrip : backgroundGrid)
	{
		for (ITile* tile : tileStrip)
		{
			tile->drawTile();
		}
	}

	//Draw every creature
	for (CreatureTile* creatureTile : creatures)
	{
		creatureTile->drawTile();
	}
}

void World::setCreatureTile(CreatureTile* creature)
{
	//Get the location of this entity
	int targetX = creature->getX();
	int targetY = creature->getY();

	//Check if this location is nullptr
	if (getCreatureTile(targetX, targetY) != nullptr)
	{
		//There is something in the desired location. delete it from the 1d and 2d arrays and insert the new one
		CreatureTile* presentCreature = getCreatureTile(targetX, targetY);
		creatures.erase(std::remove(creatures.begin(), creatures.end(), presentCreature), creatures.end()); //remove present creature from 1d array. not sure if this works yet
		delete creatureGrid[targetY][targetX]; //delete the actual object
	}

	//put the creature into the arrays
	creatureGrid[targetY][targetX] = creature; //add it to the 2d grid array
	creatures.push_back(creature); //also add it to the 1d array
}

void World::setBackgroundTile(ITile* backgroundTile)
{

}

CreatureTile* World::getCreatureTile(int x, int y)
{
	return creatureGrid[y][x];
}

ITile* World::getBackgroundTile(int x, int y)
{
	return backgroundGrid[y][x];
}

World::~World()
{
}