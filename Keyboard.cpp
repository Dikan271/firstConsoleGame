#include "Keyboard.h"

bool keyboard::IsCommand(int key)
{
	switch (key)
	{
	case Command::command_STOP:
	case Command::command_PAUSE:
	case Command::command_TEST:
	case Command::command_ENTER:
		return true;
	}
	return false;
}

bool keyboard::IsDirection(int key)
{
	switch (key)
	{
	case Direction::dir_DOWN:
	case Direction::dir_UP:
	case Direction::dir_LEFT:
	case Direction::dir_RIGHT:
		return true;
	}
	return false;
}

Direction keyboard::GetDirection(int key)
{
	switch (key)
	{
	case Direction::dir_DOWN:  return dir_DOWN; 
	case Direction::dir_UP:    return dir_UP; 
	case Direction::dir_LEFT:  return dir_LEFT; 
	case Direction::dir_RIGHT: return dir_RIGHT; 
	}
}
