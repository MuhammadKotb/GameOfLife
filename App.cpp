#include <iostream>
#include <vector>
#include <array>
#include <SFML/Graphics.hpp>
#include "MACROS.H"
#include "GridDrawer.h"
#include "Controller.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "GameOfLife", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(0);

	Grid* grid = new Grid();
	GridDrawer* gridDrawer = new GridDrawer(grid);
	Controller* controller = new Controller(grid);
	bool started = false;
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

		while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			started = false;

			unsigned int row = sf::Mouse::getPosition(window).y / 10;
			unsigned int col = sf::Mouse::getPosition(window).x / 10;
			Cell* current_cell = grid->getCellByPosition(row, col);

			if (current_cell != nullptr)
			{
				current_cell->rect->setFillColor(sf::Color::Black);
				current_cell->last_dead = false;


				window.draw(*current_cell->rect);
			}
			
			window.display();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) 
		{
			started = true;
		}
		if (started)
		{
			controller->step();
		}
		log("before second display");
		window.clear();
		gridDrawer->draw(window, started);
		window.display();
		
	}
	delete (grid);

	delete (gridDrawer);
}