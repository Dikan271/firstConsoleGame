#pragma once
#ifndef _WINDOW_H
#define _WINDOW_H

#include <iostream>
#include <fstream>
#include <string>
#include "ConsoleController.h"
#include "Position_XY.h"
#include "Dimensions.h"

using namespace std;

class Window
{
public:
	Window();
	Window(int height, int width);
	Window(string namefile);
	~Window();
	void SetText(string text);
	void SetTopLeftPosition(Position_XY topLeftposition);
	void Open();
	void Close();
	bool IsOpen();
private:
	Position_XY topLeftPosition;
	bool isFile;
	bool isOpen;
	bool isConcreteTopLeft;
	string GetTextFromFile(fstream &file);
	Dimensions GetDimensionOfWindow();
	Position_XY GetTopLeftPosition();
	Position_XY GetTopLeftPositionForCentralWindow();
	int GetHeightWindow();
	int GetWidthWindow();
	void PrintOutline(Position_XY coordinate);
	void Print(Position_XY coordinate);
protected:
	string text;
	Dimensions sizes;
};

#endif
