#pragma once
#ifndef _FIELD_H
#define _FIELD_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Dimensions.h"
#include "Position_XY.h"
#include "Item.h"

using namespace std;

class Field
{
public:
	Field();
	Field(string nameMap);
	Dimensions GetSize();
	Item GetItem(Position_XY coordinate);
	bool CheckWall(Position_XY coordinate);
	void SetLocation(string nameMap);
	void Print();
private:
	Dimensions sizes;
	string nameLocation;
	vector< string > item;
	vector< vector< bool > > wall;
	Dimensions GetSize(string txt_Location);
	string GetTextFromFile();
	void InitializationMap();
	bool IsItem(char simbol);
};
#endif