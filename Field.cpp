#include "Field.h"

Field::Field()
{
	Field("map2");
}

Field::Field(string nameMap)
{
	SetLocation(nameMap);
}

Dimensions Field::GetSize()
{
	return sizes;
}

Item Field::GetItem(Position_XY coordinate)
{
	return item[coordinate.y][coordinate.x];
}

bool Field::CheckWall(Position_XY coordinate)
{
	return wall[coordinate.y][coordinate.x];
}

void Field::SetLocation(string nameMap)
{
	nameLocation = "file/" + nameMap + ".txt";
	InitializationMap();
}

void Field::InitializationMap()
{
	string text = GetTextFromFile();
	sizes = GetSize(text);
	item.resize(sizes.height);
	wall.resize(sizes.height);
	int iter = 0;
	for (int i = 0; i < sizes.height; i++)
	{
		for (int j = 0; j <= sizes.width; j++, iter++)
		{
			char simbol = text[iter];
			if (IsItem(simbol))
			{
				item[i].push_back(simbol);
				wall[i].push_back(false);
			}
			else
			{
				item[i].push_back(' ');
				wall[i].push_back(true);
			}
		}
	}
}

string Field::GetTextFromFile()
{
	string txt;
	fstream file(nameLocation, ios_base::in);
	char simbol;
	while ((simbol = file.get()) != EOF)
	{
		txt += simbol;
	}
	return txt;
}

Dimensions Field::GetSize(string txt_Location)
{
	int heigth = 0;
	int length = txt_Location.size();
	for (int i = 0; i < length; i++)
	{
		if (txt_Location[i] == '\n')
			heigth++;
	}
	length /= ++heigth;
	Dimensions size = { length, heigth };
	return size;
}

bool Field::IsItem(char simbol)
{
	Item item(simbol);
	string name = item.GetName();
	return name != "unknow ";
}


void Field::Print()		//TODO
{
	for (int i = 0; i < sizes.height; i++)
	{
		for (int j = 0; j <= sizes.width; j++)
		{
			if (wall[i][j]) cout << '#';
			else cout << item[i][j];
		}
		cout << endl;
	}
}