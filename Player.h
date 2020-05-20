#pragma once
#ifndef _PLAYER_H
#define _PLAYER_H

#include "Mob.h"

class Player :
	public Mob
{
public:
	Player();
	Player(Position_XY position);
	bool Take(Item item);
private:
};

#endif