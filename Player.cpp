#include "Player.h"

Player::Player()
{
}

Player::Player(Position_XY position) : Mob(position)
{
}

bool Player::Take(Item item)
{
	return bag.PushItem(item);
}
