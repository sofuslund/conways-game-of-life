#include "Game.h"

void Game::handleEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        // Close the window if a close event was recieved.
        if (event.type == sf::Event::Closed)
            window.close();
        else if (event.type == sf::Event::KeyPressed)
        {
            // Enable or disable drawing and grid mode

            if (event.key.code == sf::Keyboard::D)
            {
                drawEnabled = !drawEnabled;
                std::string msg = drawEnabled ? "Drawing mode enabled. " : "Drawing mode disabled ";
                std::cout << msg << std::endl;
            }
            if (event.key.code == sf::Keyboard::G)
            {
                gridEnabled = !gridEnabled;
                std::string msg = gridEnabled ? "Grid enabled. " : "Grid disabled. ";
                std::cout << msg << std::endl;
            }
        }
        // Toggle is mouse is down
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                mouseDown = true;
            }
        }
        else if (event.type == sf::Event::MouseButtonReleased)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                mouseDown = false;
            }
        }
    }
}

void Game::update()
{
    if (drawEnabled)
    {
        if (mouseDown)
        {
            // Find the cordinates of the nearest cell from the mouse position
            int cellX = sf::Mouse::getPosition(window).x / cells.cellWidth;
            int cellY = sf::Mouse::getPosition(window).y / cells.cellHeight;
            // Set the cell alive if it is in bound
            if (cellX > 0 && cellX < cells.cellsX && cellY > 0 && cellY < cells.cellsY)
            {
                cells.setState(cellX, cellY, state::live);
            }
        }
        return;
    }

    // Update next cell generation
    CellMatrix newGen(window.getSize().x, window.getSize().y);
    for (int x = 0; x < cells.cellsX; x++)
    {
        for (int y = 0; y < cells.cellsY; y++)
        {
            int liveNeighbours = cells.getLiveCellsSurrounding(x, y);
            // If a living cell survives
            if (cells.getState(x, y) == state::live && liveNeighbours == 2 || liveNeighbours == 3)
            {
                newGen.setState(x, y, state::live);
            }
            // If a dead cell reproduces
            else if (cells.getState(x, y) == state::dead && liveNeighbours == 3)
            {
                newGen.setState(x, y, state::live);
            }
        }
    }
    cells.setNewMatrix(newGen);
}

void Game::drawGrid()
{
}

void Game::display()
{
    window.clear(sf::Color::Black);
    if (gridEnabled)
    {
        drawGrid();
    }
    cells.display(&window);
    window.display();
}

bool Game::isRunning()
{
    return window.isOpen();
}