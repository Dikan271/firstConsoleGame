#include "Game.h"
#include <string>
//
// TODO: take item
//		 respawn item
//
int main()
{
	Game game;
	game.SetLocation("map2");
	game.StartGame();
	while (1)
	{
		game.Control();
		game.Print();
	}
}
