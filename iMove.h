#pragma once
#ifndef _IMOVE_H
#define _IMOVE_H
#include"Keyboard.h"
#include "Position_XY.h"

class iMove
{
public:
	iMove(Position_XY position);
	Position_XY Move(Direction direction);
	
private:
	int speed;
	Position_XY position;
};

#endif 