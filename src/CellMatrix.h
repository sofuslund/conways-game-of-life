#pragma once
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <vector>
#include <iostream>

enum class state : bool
{
	dead = false,
	live = true
};

class CellMatrix
{
private:
	std::vector<std::vector<state>> cells;
public:
	CellMatrix(int screenWidth, int screenHeight);

	int cellsX, cellsY, cellWidth, cellHeight, screenWidth, screenHeight;
	sf::Color deadCol, liveCol;

	void setCellSize(int width, int height);
	void setState(int x, int y, state s);
	void setNewMatrix(CellMatrix matrix);

	state getState(int x, int y);
	int getLiveCellsSurrounding(int x, int y);

	void print();
	void display(sf::RenderWindow* window);
};