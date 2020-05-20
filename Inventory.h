#pragma once
#ifndef _INVENTORY_H
#define _INVENTORY_H

#include <vector>
#include "Item.h"

using namespace std;

class Inventory
{
public:
	Inventory();
	Item GetItem(int index);
	bool PopItem(int index);
	bool PushItem(Item item);
	int GetCapasity();
private:
	int capacity = 25;
	int emptyCells = 25;
	vector< Item > container;
	void ClearCell(int index);
	bool Add(Item item);
	int GetFreeCell();
	bool IsFreeCell(int index);
	bool IsExist(int index);
	bool CheckContainerIsFull();
	int GetIndexForNewItem(Item nameItem);
	bool IsNeedCell(Item ourItem, Item otherItem);
	bool IsEquallyItems(Item ourItem, Item item);
	bool IsSteckWillBeFull(Item ourItem, Item otherItem);
	void PushInNewCell(int index, Item item);
	void PushInExistItem(int index, Item item);
};

#endif
