#include "IteratorForFileOfInventory.h"

IteratorForFileOfInventory::IteratorForFileOfInventory()
{
	countCell = 0;
	countRow = 1;
	index = calculation(countRow, countCell);
}

void IteratorForFileOfInventory::setIndex(int i)
{
	for (int j = 0; j < i; j++)
	{
		operator++();
	}
}

IteratorForFileOfInventory& IteratorForFileOfInventory::operator++()
{
	if (countCell >= 4)
	{
		countCell = 0;
		countRow += 3;
	}
	else
	{
		countCell++;
	}
	index = calculation(countRow, countCell);
	return *this;
}

int IteratorForFileOfInventory::getIndexOfCount()
{
	return index + sizeRow;
}

int IteratorForFileOfInventory::getIndexOfName()
{
	return index;
}

int IteratorForFileOfInventory::calculation(const int RowNumber, const int  columnNumber)
{
	return sizeRow * RowNumber + leftEdge + sizeCell * columnNumber;
}
