#pragma once
#ifndef _KEYBOARD_H
#define _KEYBOARD_H

enum Direction
{
	dir_UP = 'w',
	dir_DOWN = 's',
	dir_LEFT = 'a',
	dir_RIGHT = 'd'
};

enum Command
{
	command_STOP = 8,   // backspase
	command_PAUSE = 27, // esc
	command_ENTER = 13, // enter
	command_TEST = 32   // space
};

namespace keyboard
{
	bool IsCommand(int key);
	bool IsDirection(int key);
	Direction GetDirection(int key);
}
#endif
