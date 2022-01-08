// Conway's Game of Life
// Rules:
// 1. Any live cell with two or three live neighbours survives.
// 2. Any dead cell with three live neighbours becomes a live cell.
// 3. All other live cells die in the next generation. Similarly, all other dead cells stay dead.

#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>

#include "Game.h";

const std::string title = "Conway's Game of Life";
const int width = 1200, height = 900;

int main()
{
    std::cout << " --- --- --- Conway's Game of Life --- --- --- " << std::endl;
    std::cout << "Press 'd' to enable or disable drawing mode    " << std::endl;
    std::cout << "Press 'g' to enable or disable grid            " << std::endl;

    Game game(width, height, title);

    while (game.isRunning())
    {
        game.display();
        game.handleEvents();
        game.update();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000/120));
    }

    return 0;
}