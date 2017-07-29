#include "window.h"
#include "game.h"

int main()
{
	using namespace sebtd;

	/*graphics::Window window("SebTD", 800, 450);*/
	graphics::Window window("SebTD", 1600, 900);
	controller::Game game(window);

	// start the game
	game.start();

	return 0;
}