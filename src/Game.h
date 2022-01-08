#pragma once
#include <SFML/Graphics.hpp>
#include "CellMatrix.h"

class Game
{
private:
	sf::RenderWindow window;
	CellMatrix cells;
	bool drawEnabled;
	bool gridEnabled;
	bool mouseDown;
	void drawGrid();
public:
	Game(int width, int height, std::string title) : 
		window(sf::VideoMode(width, height), title, sf::Style::Titlebar | sf::Style::Close),
		cells(width, height), 
		drawEnabled(false), 
		gridEnabled(false), 
		mouseDown(false)
	{
		cells.setCellSize(20, 20);
	}
	bool isRunning();
	void handleEvents();
	void update();
	void display();
};