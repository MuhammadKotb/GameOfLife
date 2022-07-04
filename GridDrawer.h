#pragma once
#include <array>
#include <SFML/Graphics.hpp>
#include "MACROS.H"

constexpr unsigned int ROW_NUM = 36;
constexpr unsigned int COL_NUM = 64;
constexpr unsigned int CELL_WIDTH = 20;


struct Cell {
	bool current_dead = true;
	bool last_dead = true;
	bool chosen = false;
	unsigned int row = 0;
	unsigned int col = 0;
	sf::RectangleShape* rect = nullptr;
};

struct Grid {
	Cell* cells[ROW_NUM][COL_NUM];
	Grid();
	~Grid();
	Cell* getCellByPosition(const unsigned int row, const unsigned int col);
};
class GridDrawer
{
private:
	
	Grid* grid;
	
public:

	GridDrawer(Grid* grid);
	~GridDrawer();

	void draw(sf::RenderWindow& window, bool started);
};


