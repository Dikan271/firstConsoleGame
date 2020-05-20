#pragma once
#ifndef _GAME_H
#define _GAME_H

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "Field.h"
#include "Keyboard.h"
#include "Window.h"
#include "WinInventory.h"
#include "iMove.h"
#include "Mob.h"
#include "Player.h"
#include "Position_XY.h"
#include "Dimensions.h"
#include "ConsoleController.h"

extern Field location;

class Game
{
public:
	Game();
	void SetLocation(string startLocation);
	void StartGame();
	void EndGame();
	bool Control();
	void Print();
private:
	Field location;
	Player hiro;
	WinInventory menu;
	int  windowIsOpen;
	Position_XY GetStartHiroPosition();
	void PrintMoveObject(Position_XY position, Item previous, char objectForMove);
	void CallMenu(Mob* masterOfInventory);
	void OpenMenu(Mob* masterOfInventory);
	void CloseMenu();
	void MoveObject(int key, Mob* moveMan);
	bool SeeIfICanMove(Direction direction, Mob* moveMan);
	void CommandManager(int key);
	void TakeItem(Player* masterOfInventory);
};

#endif