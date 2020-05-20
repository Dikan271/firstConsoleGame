#include "Inventory.h"

Inventory::Inventory()
{
	container.resize(capacity);
}

Item Inventory::GetItem(int index)
{
	return container[index];
}

bool Inventory::PopItem(int index)
{
	if (IsFreeCell(index)) return false;
	container[index] -= 1;
	if (IsFreeCell(index))
		ClearCell(index);
	return true;
}

void Inventory::ClearCell(int index)
{
	Item freeCell;
	container[index].SetItem(freeCell);
	emptyCells++;
}

bool Inventory::PushItem(Item item)
{
	if (CheckContainerIsFull()) return false;
	return Add(item);
}

int Inventory::GetCapasity()
{
	return capacity;
}

bool Inventory::Add(Item item)
{
	int index = GetIndexForNewItem(item);
	bool isExist = IsExist(index);
	if (isExist)
		PushInExistItem(index, item);
	else
	{
		index = GetFreeCell();
		PushInNewCell(index, item);
	}
	return true;
}

int Inventory::GetFreeCell()
{
	for (int i = 0; i < capacity; i++)
	{
		if (IsFreeCell(i))
			return i;
	}
}

bool Inventory::CheckContainerIsFull()
{
	return emptyCells == 0;
}

bool Inventory::IsFreeCell(int index)
{
	return container[index].GetCounter() == 0;
}

bool Inventory::IsExist(int index)
{
	return index >= 0;
}

int Inventory::GetIndexForNewItem(Item item)
{
	for (int i = 0; i < capacity; i++)
	{
		if (IsNeedCell(container[i], item))
			return i;
	}
	return -1;
}

bool Inventory::IsNeedCell(Item ourItem, Item otherItem)
{
	return (IsEquallyItems(ourItem, otherItem) &&
			!IsSteckWillBeFull(ourItem, otherItem));
}

bool Inventory::IsEquallyItems(Item ourItem, Item newItem)
{
	return ourItem.GetName() == newItem.GetName();
}

bool Inventory::IsSteckWillBeFull(Item ourItem, Item otherItem)
{
	int sum = ourItem.GetCounter() + otherItem.GetCounter();
	return  sum > 65;
}

void Inventory::PushInNewCell(int index, Item item)
{
	container[index].SetItem(item);
	emptyCells--;
}

void Inventory::PushInExistItem(int index, Item item)
{
	//TODO if IsSteckWillBeFull
	container[index] += item.GetCounter();
}
