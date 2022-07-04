#include "Controller.h"


Controller::Controller(Grid* grid)
{
	this->grid = grid;
}

Controller::~Controller()
{
}

bool Controller::isUnderPop()
{
	// check left 

	return false;
}

bool Controller::isOverPop()
{
	return false;
}

bool Controller::nextGen()
{
	return false;
}

bool Controller::isReprod()
{
	return false;
}


void Controller::step()
{
	for (auto& row : this->grid->cells)
	{
		for (auto& cell : row)
		{
			
		}
	}
}



