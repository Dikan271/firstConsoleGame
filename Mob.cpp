#include "Mob.h"

Mob::Mob()
{
	position.x = 0;
	position.y = 0;
}

Mob::Mob(Position_XY position)
{
	this->position = position;
	speed = 1;
}

void Mob::Move(Direction direction)
{
	iMove move(position);
	position = move.Move(direction);
}

Position_XY Mob::GetPosition()
{
	return position;
}

void Mob::SetPosition(Position_XY position)
{
	this->position = position;
}

Inventory Mob::GetInventory()
{
	return bag;
}

void Mob::Set_Form(char forma)
{
	form = forma;
}

char Mob::Get_Form()
{
	return form;
}
