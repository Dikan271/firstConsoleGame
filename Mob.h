#pragma once
#ifndef _MOB_H
#define _MOB_H

#include "Keyboard.h"
#include "Position_XY.h"
#include "iMove.h"
#include "Inventory.h"

class Mob
{
public:
	Mob();
	Mob(Position_XY position);
	void Move(Direction direction);
	Position_XY GetPosition();
	void SetPosition(Position_XY position);
	void Set_Form(char forma);
	char Get_Form();
	Inventory GetInventory();
private:
	int speed;
	Position_XY position;
protected:
	char form = -2;
	Inventory bag;
};

#endif
