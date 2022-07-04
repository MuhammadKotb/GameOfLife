#include "Controller.h"


Controller::Controller(Grid* grid)
{
	this->grid = grid;
}

Controller::~Controller()
{
}

unsigned int Controller::livingNeighbours(const unsigned int row, const unsigned int col) const
{
	unsigned int ctr = 0;
	Cell* leftCell = this->grid->getCellByPosition(row, col - 1);
	Cell* rightCell = this->grid->getCellByPosition(row, col + 1);
	Cell* downCell = this->grid->getCellByPosition(row + 1, col);
	Cell* upCell = this->grid->getCellByPosition(row - 1, col);
	Cell* upLeftCell = this->grid->getCellByPosition(row - 1, col - 1);
	Cell* upRightCell = this->grid->getCellByPosition(row - 1, col + 1);
	Cell* downLeftCell = this->grid->getCellByPosition(row + 1, col - 1);
	Cell* downRightCell = this->grid->getCellByPosition(row + 1, col + 1);


	if (leftCell)
	{
		ctr += !leftCell->last_dead;
	}
	if (rightCell)
	{
		ctr += !rightCell->last_dead;
	}
	if (downCell)
	{
		ctr += !downCell->last_dead;
	}
	if (upCell)
	{
		ctr += !upCell->last_dead;
	}
	if (upLeftCell)
	{
		ctr += !upLeftCell->last_dead;
	}
	if (upRightCell)
	{
		ctr += !upRightCell->last_dead;
	}
	if (downLeftCell)
	{
		ctr += !downLeftCell->last_dead;
	}
	if (downRightCell)
	{
		ctr += !downRightCell->last_dead;
	}

	return ctr;
}

bool Controller::isUnderPop(const unsigned int row, const unsigned int col) const 
{
	return livingNeighbours(row, col) <= 1;
}

bool Controller::isOverPop(const unsigned int row, const unsigned int col) const 
{
	return livingNeighbours(row, col) >= 4;
}

bool Controller::nextGen(const unsigned int row, const unsigned int col) const 
{
	unsigned int alive = livingNeighbours(row, col);
	return alive == 2 || alive == 3;
}

bool Controller::isReprod(const unsigned int row, const unsigned int col) const 
{
	return livingNeighbours(row, col) == 3;

}


void Controller::step()
{
	for (int i = 0; i < ROW_NUM; i++)
	{
		for (int j = 0; j < COL_NUM; j++)
		{
			Cell* current_cell = this->grid->cells[i][j];

			// alive
			if (!current_cell->last_dead)
			{
				if (!nextGen(i, j))
				{

					current_cell->current_dead = true;
				}
				else
				{
					current_cell->current_dead = false;
				}
			}
			// dead
			else
			{
				if (isReprod(i, j))
				{
					current_cell->current_dead = false;
				}
				else
				{
					current_cell->current_dead = true;
				}
			}
		}
	}
	
}



