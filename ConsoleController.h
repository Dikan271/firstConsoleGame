#pragma once
#ifndef _CONSOLECONTROLLER_H
#define _CONSOLECONTROLLER_H

#include <windows.h>
#include "Position_XY.h"
#include "Dimensions.h"

class ConsoleController
{
public:
	ConsoleController();
	void DeleteCursor();
	void SetCursorPosition(Position_XY position);
	void SetColor(unsigned short color);
	Dimensions GetSizeConsole();
private:
	HANDLE output;
};

#endif // !_CONSOLECONTROLLER_H
