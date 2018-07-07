#pragma once
//C++ includes
#include <vector>
//My includes
#include "../entities/ITile.h"
#include "../entities/CreatureTile.h"

class World
{
public:
	World(int width, int height);
	virtual ~World();

	void runWorld();
	void drawWorld();

	CreatureTile* getCreatureTile(int x, int y);
	ITile* getBackgroundTile(int x, int y);

	void setCreatureTile(CreatureTile* creature);
	void setBackgroundTile(ITile* backgroundTile);

private:
	int worldWidth, worldHeight;
	unsigned long worldTime;

	//2D vectors for grid
	std::vector<std::vector<CreatureTile*>> creatureGrid;
	std::vector<std::vector<ITile*>> backgroundGrid;

	//1D vectors for running things
	std::vector<CreatureTile*> creatures; //all creatures are runnable, so all creatures must be in this 
	std::vector<ITile*> backgroundTiles; //as of now, only runnable background tiles will be in this vector
};