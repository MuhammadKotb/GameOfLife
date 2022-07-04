#include <iostream>
#include <vector>
#include <array>
#include <SFML/Graphics.hpp>
#include "MACROS.H"
#include "GridDrawer.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "GameOfLife", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(0);

	Grid* grid = new Grid();

	GridDrawer* gridDrawer = new GridDrawer(grid);


	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			unsigned int row = sf::Mouse::getPosition(window).y / 10;
			unsigned int col = sf::Mouse::getPosition(window).x / 10;
			Cell* current_cell = grid->getCellByPosition(row, col);
			if (current_cell != nullptr)
			{
				current_cell->rect->setFillColor(sf::Color::Black);
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			unsigned int row = sf::Mouse::getPosition(window).y / 10;
			unsigned int col = sf::Mouse::getPosition(window).x / 10;
			Cell* current_cell = grid->getCellByPosition(row, col);
			if (current_cell != nullptr)
			{
				current_cell->rect->setFillColor(sf::Color(GREY));
			}
		}

		window.clear();
		gridDrawer->draw(window);
		window.display();
	}
	delete (grid);

	delete (gridDrawer);
}