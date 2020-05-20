#include "WinInventory.h"

WinInventory::WinInventory() : Window("file/Inventory.txt")
{
}

void WinInventory::SetINventory(Inventory * inventr_ptr)
{
	inventr = inventr_ptr;
}

void WinInventory::Open()
{
	SettingOfInventoryInWindow();
	Window::Open();
}

void WinInventory::Close()
{
	Window::Close();
}

void WinInventory::SettingOfInventoryInWindow()
{
	int capacity = inventr->GetCapasity();
	IteratorForFileOfInventory index;
	for (int i = 0; i < capacity; i++)
	{
		Item item = inventr->GetItem(i);
		bool thisCellIsEmpty= item.GetCounter() == 0;
		if(!thisCellIsEmpty)
			FillOfCell(item, index);
		++index;
	}
}

void WinInventory::FillOfCell(Item item, IteratorForFileOfInventory index)
{
	InsertName(item, index);
	InsertCount(item, index);
}

void WinInventory::InsertName(Item item, IteratorForFileOfInventory index)
{
	int positionOfName = index.getIndexOfName();
	string nameItem = item.GetName();
	Insert(positionOfName, nameItem);
}

void WinInventory::InsertCount(Item item, IteratorForFileOfInventory index)
{
	int positionOfCount = index.getIndexOfCount();
	string countForCell = ConvertCountToStringForCell(item);
	Insert(positionOfCount, countForCell);
}

string WinInventory::ConvertCountToStringForCell(Item item)
{
	int number = item.GetCounter();
	string stringCount = ConvertNumberToString(number);
	stringCount.insert(0, "x:");
	const int sizeOfCell = 7;
	if (stringCount.size() != sizeOfCell)
	{
		int x = sizeOfCell - stringCount.size();
		while (x--)
			stringCount.insert(0, " ");
	}
	return stringCount;
}

string WinInventory::ConvertNumberToString(int number)
{
	string stringCount;
	char value;
	do
	{	
		value = SimbolFromNumber(number);
		stringCount.push_back(value);
		number = DeleteEndNumber(number);
	} while (number > 0);
	reverse(stringCount.begin(), stringCount.end());
	return stringCount;
}

char WinInventory::SimbolFromNumber(int number)
{
	return (char('0' + number % 10));
}

int WinInventory::DeleteEndNumber(int  value)
{
	return value / 10;
}

void WinInventory::Insert(int index, string info)
{	
	const int sizeOfCell = 7;
	for (int j = 0; j < sizeOfCell; j++)
		text[index + j] = info[j];
}