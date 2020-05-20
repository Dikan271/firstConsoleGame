#pragma once
#ifndef _ITEM_H
#define _ITEM_H

#include <iostream>
#include <string>

using namespace std;

class Item
{
public:
	Item();
	Item(char simbol);
	int GetCounter();
	string GetName();
	void SetItem(Item &object);
	void operator -=(int value);
	void operator +=(int value);
	friend ostream& operator <<(ostream &os, Item dd);
private:
	int counter;
	char simbol;
	string ConvertNameToString();
};

#endif 
