#include "GridDrawer.h"


GridDrawer::GridDrawer(Grid* grid)
{
	this->grid = grid;
}


GridDrawer::~GridDrawer()
{
	
}


void GridDrawer::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < ROW_NUM; i++)
	{
		for (int j = 0; j < COL_NUM; j++)
		{
			window.draw(*this->grid->cells[i][j]->rect);
		}
	}
}



Grid::Grid()
{
	int posX = 0;
	int posY = 0;

	for (int i = 0; i < ROW_NUM; i++)
	{
		for (int j = 0; j < COL_NUM; j++)
		{
			this->cells[i][j] = new Cell();
			this->cells[i][j]->rect = new sf::RectangleShape();
			this->cells[i][j]->rect->setFillColor(sf::Color(SILVER));
			this->cells[i][j]->rect->setSize(sf::Vector2f(CELL_WIDTH - 1, CELL_WIDTH - 1));
			this->cells[i][j]->rect->setPosition(posX, posY);
			this->cells[i][j]->row = i;
			this->cells[i][j]->col = j;
			posX += 10;
		}
		posX = 0;
		posY += 10;
	}
}
Grid::~Grid()
{
	for (int i = 0; i < ROW_NUM; i++)
	{
		for (int j = 0; j < COL_NUM; j++)
		{
			delete(cells[i][j])->rect;
			delete(cells[i][j]);

		}
	}
}

Cell* Grid::getCellByPosition(const unsigned int row, const unsigned int col)
{
	if (row < ROW_NUM && col < COL_NUM && row >= 0 && col >= 0)
	{
		return this->cells[row][col];
	}
	return nullptr;
}
