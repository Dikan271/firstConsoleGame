#include "ConsoleController.h"

ConsoleController::ConsoleController()
{
	output = GetStdHandle(STD_OUTPUT_HANDLE);
}

void ConsoleController::DeleteCursor()
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(output, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(output, &structCursorInfo);
}

void ConsoleController::SetCursorPosition(Position_XY position)
{
	COORD pos = { position.x, position.y };
	SetConsoleCursorPosition(output, pos);
}

Dimensions ConsoleController::GetSizeConsole()
{
	Dimensions size;
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(output, &consoleInfo);
	size.width = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
	size.height = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
	return size;
}

void ConsoleController::SetColor(unsigned short color)
{
	SetConsoleTextAttribute(output, color);
}