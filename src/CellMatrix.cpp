#include "CellMatrix.h"

CellMatrix::CellMatrix(int screenWidth, int screenHeight)
{
	cellWidth = 5;
	cellHeight = 5;
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
	cellsX = screenWidth / cellWidth;
	cellsY = screenHeight / cellHeight;

	liveCol = sf::Color::Black;
	deadCol = sf::Color::White;
	
	// Make all cells dead
	cells.resize(cellsY);
	for (auto& x : cells)
	{
		x.resize(cellsX);
		std::fill(x.begin(), x.end(), state::dead);
	}
}

void CellMatrix::setCellSize(int width, int height)
{
	cellWidth = width;
	cellHeight = height;
	cellsX = screenWidth / cellWidth;
	cellsY = screenHeight / cellHeight;

	cells.resize(cellsY);
	for (auto& x : cells)
	{
		x.resize(cellsX);
	}
}

state CellMatrix::getState(int x, int y)
{
	return cells.at(y).at(x);
}

void CellMatrix::setState(int x, int y, state s)
{
	cells.at(y).at(x) = s;
}

void CellMatrix::setNewMatrix(CellMatrix matrix)
{
	this->cells.assign(matrix.cells.begin(), matrix.cells.end());
}

int CellMatrix::getLiveCellsSurrounding(int x, int y)
{
	int result = 0;
	for (int relX = -1; relX <= 1; relX++)
	{
		for (int relY = -1; relY <= 1; relY++)
		{
			bool outOfBound = x + relX < 0 || y + relY < 0 || x + relX >= cellsX || y + relY >= cellsY;
			if (!(relX == 0 && relY == 0) && !outOfBound)
			{
				result += int(getState(x + relX, y + relY));
			}
		}
	}
	return result;
}

void CellMatrix::print()
{
	for (auto y : cells)
	{
		for (auto x : y)
		{
			std::cout << (x == state::live) << " ";
		}
		std::cout << std::endl;
	}
}

void CellMatrix::display(sf::RenderWindow* window)
{
	sf::RectangleShape cellShape(sf::Vector2f((float)cellWidth, (float)cellHeight));
	for (int y=0; y < cells.size(); y++)
	{
		for (int x = 0; x < cells.at(y).size(); x++)
		{
			sf::Color fillColor = (cells.at(y).at(x) == state::dead) ? deadCol : liveCol;
			cellShape.setFillColor(fillColor);
			cellShape.setPosition((float)(x * cellWidth), (float)(y * cellHeight));
			window->draw(cellShape);
		}
	}
}