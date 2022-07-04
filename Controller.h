#pragma once
#include "MACROS.H"
#include "GridDrawer.h"
#include <array>
class Controller
{
private:
	Grid* grid;
public:
	Controller(Grid* grid);
	~Controller();
	unsigned int livingNeighbours(const unsigned int row, const unsigned int col) const;
	bool isUnderPop(const unsigned int row, const unsigned int col) const ;
	bool isOverPop(const unsigned int row, const unsigned int col) const ;
	bool nextGen(const unsigned int row, const unsigned int col) const ;
	bool isReprod(const unsigned int row, const unsigned int col) const ;
	void step();
};

