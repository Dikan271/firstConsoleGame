#pragma once
#ifndef _WININVENTORY_H
#define _WININVENTORY_H

#include <fstream>
#include "Window.h"
#include "Inventory.h"
#include "IteratorForFileOfInventory.h"

class WinInventory : public Window //todo
{
public:
	WinInventory();
	void SetINventory(Inventory* inventr_ptr);
	void Open();
	void Close();
private:
	Inventory* inventr;
	void SettingOfInventoryInWindow();
	void FillOfCell(Item item, IteratorForFileOfInventory index);
	void InsertName(Item item, IteratorForFileOfInventory index);
	void InsertCount(Item item, IteratorForFileOfInventory index);
	string ConvertCountToStringForCell(Item item);
	string ConvertNumberToString(int number);
	char SimbolFromNumber(int number);
	int DeleteEndNumber(int value);
	void Insert(int index, string info);
};
#endif