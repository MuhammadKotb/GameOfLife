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
	bool isUnderPop();
	bool isOverPop();
	bool nextGen();
	bool isReprod();
	void step();
};

