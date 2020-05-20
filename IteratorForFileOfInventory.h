#pragma once
#ifndef _ITERATORFORFILEOFINVENTORY_H
#define _ITERATORFORFILEOFINVENTORY_H

class IteratorForFileOfInventory
{
public:
	IteratorForFileOfInventory();
	void setIndex(int i);
	IteratorForFileOfInventory& operator++();
	int getIndexOfName();
	int getIndexOfCount();
private:
	int index;
	const int sizeRow = 57;
	const int sizeCell = 8;
	const int leftEdge = 16;
	int countRow;
	int countCell;
	int calculation(const int RowNumber, const  int  columnNumber);
};

#endif 
