#include "iMove.h"

iMove::iMove(Position_XY position)
{
	this->position = position;
	speed = 1;
}

Position_XY iMove::Move(Direction direction)
{
	switch (direction)
	{
	case dir_UP:
		position.y--;
		break;
	case dir_DOWN:
		position.y++;
		break;
	case dir_LEFT:
		position.x--;
		break;
	case dir_RIGHT:
		position.x++;
		break;
	}
	return position;
}