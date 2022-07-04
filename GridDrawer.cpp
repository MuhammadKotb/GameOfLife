#include "GridDrawer.h"


GridDrawer::GridDrawer(Grid* grid)
{
	this->grid = grid;
}


GridDrawer::~GridDrawer()
{
	
}


void GridDrawer::draw(sf::RenderWindow& window, bool started)
{
	for (int i = 0; i < ROW_NUM; i++)
	{
		for (int j = 0; j < COL_NUM; j++)
		{
			if (started)
			{
				if (this->grid->cells[i][j]->current_dead)
				{
					this->grid->cells[i][j]->rect->setFillColor(sf::Color(SILVER));
				}
				else
				{
					this->grid->cells[i][j]->rect->setFillColor(sf::Color::Black);
				}
				this->grid->cells[i][j]->last_dead = this->grid->cells[i][j]->current_dead;

			}
			if (this->grid->cells[i][j]->chosen)
			{
				this->grid->cells[i][j]->rect->setOutlineColor(sf::Color::Red);
				this->grid->cells[i][j]->rect->setOutlineThickness(1.5);
			}
			else
			{
				this->grid->cells[i][j]->rect->setOutlineColor(this->grid->cells[i][j]->rect->getFillColor());
				this->grid->cells[i][j]->rect->setOutlineThickness(0);
			}

			window.draw(*this->grid->cells[i][j]->rect);
			this->grid->cells[i][j]->chosen = false;
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
			posX += CELL_WIDTH;
		}
		posX = 0;
		posY += CELL_WIDTH;
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
