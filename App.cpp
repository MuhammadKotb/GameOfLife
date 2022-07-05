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


	sf::RenderTexture renderTextur;

	renderTextur.create(WINDOW_WIDTH, WINDOW_HEIGHT);



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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		const unsigned int row = sf::Mouse::getPosition(window).y / CELL_WIDTH;
		const unsigned int col = sf::Mouse::getPosition(window).x / CELL_WIDTH;

		Cell* current_cell = grid->getCellByPosition(row, col);
		if (current_cell != nullptr)
		{
			current_cell->chosen = true;
		}
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			started = false;
			const unsigned int row = sf::Mouse::getPosition(window).y / CELL_WIDTH;
			const unsigned int col = sf::Mouse::getPosition(window).x / CELL_WIDTH;
			Cell* current_cell = grid->getCellByPosition(row, col);

			if (current_cell != nullptr)
			{
				current_cell->rect->setFillColor(sf::Color::Black);
				current_cell->last_dead = false;
			}
		}	
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{ 
			const unsigned int row = sf::Mouse::getPosition(window).y / CELL_WIDTH;
			const unsigned int col = sf::Mouse::getPosition(window).x / CELL_WIDTH;
			Cell* current_cell = grid->getCellByPosition(row, col);

			if (current_cell != nullptr)
			{
				current_cell->rect->setFillColor(sf::Color(SILVER));
				current_cell->last_dead = true;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			started = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) 
		{
			started = true;
		}
		if (started)
		{
			controller->step();
		}
		renderTextur.clear();
		gridDrawer->draw(renderTextur, started);
		renderTextur.display();
		window.clear();
		sf::Sprite sprite(renderTextur.getTexture());
		window.draw(sprite);
		window.display();

		
	}
	delete (gridDrawer);

	delete (grid);

}