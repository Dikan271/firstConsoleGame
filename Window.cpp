#include "Window.h"

Window::Window()
{
	sizes.height = 20;
	sizes.width = 40;
	isFile = false;
	isOpen = false;
	isConcreteTopLeft = false;
}

Window::Window(int height, int width) : Window()
{
	this->sizes.height = height;
	this->sizes.width = width;
}

Window::Window(string namefile) : Window()
{
	fstream file(namefile, ios_base::in);
	if (!file.is_open())
	{
		printf("File \"%s\" not found \n", namefile);
		system("pause");
		exit(6);
	}
	isFile = true;
	text = GetTextFromFile(file);
	sizes = GetDimensionOfWindow();
	file.close();
}

Window::~Window()
{
	if(isOpen)
		Close();
	text.clear();
}

void Window::SetText(string text)
{
	this->text = text;

	sizes = GetDimensionOfWindow();
}

string Window::GetTextFromFile(fstream &file)
{
	string txt;
	char simbol;
	while ((simbol = file.get()) != EOF)
	{
		txt += simbol;
	}
	return txt;
}

Dimensions Window::GetDimensionOfWindow()
{
	int length = text.length();
	Dimensions size = {0, 0};
	size.height = GetHeightWindow();
	size.width = GetWidthWindow();
	return size;
}

int Window::GetHeightWindow()
{
	int counter = 0;
	for (int i = 0; text[i] != '\0'; i++)
	{
		if (text[i] == '\n')
			counter++;
	}
	if (!isFile)
		counter += 4;
	return counter;
}

int Window::GetWidthWindow()
{
	int counter = 0;
	int mxlen = 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] == '\n')
		{
			if(mxlen < counter)
				mxlen = counter;
			counter = 0;
		}
		else counter++;
	}
	if (mxlen < counter) 
		mxlen = counter;
	if (!isFile)
		mxlen += 4;
	return mxlen;
}

void Window::SetTopLeftPosition(Position_XY topLeftPosition)
{
	this->topLeftPosition = topLeftPosition;
	isConcreteTopLeft = true;
}

void Window::Open()
{
	Position_XY position = GetTopLeftPosition();
	isOpen = true;
	if(!isFile)
	{
		PrintOutline(position);
		position.x+=2;	//because we have outline
		position.y++;
	}
	Print(position);
}

void Window::Close()
{
	isOpen = false;
	ConsoleController curcore;
	Position_XY position = topLeftPosition;
	curcore.SetCursorPosition(position);
	for (int i = 0; i <= sizes.height; i++)
	{
		for (int j = 0; j < sizes.width; j++)
			cout << ' ';
		position.y++;
		curcore.SetCursorPosition(position);
	}
}

bool Window::IsOpen()
{
	return isOpen;
}

Position_XY Window::GetTopLeftPosition()
{
	if (isConcreteTopLeft) return topLeftPosition;
	else return GetTopLeftPositionForCentralWindow();
}

Position_XY Window::GetTopLeftPositionForCentralWindow()
{
	ConsoleController console;
	Dimensions sizeConsole = console.GetSizeConsole();
	topLeftPosition.x = (sizeConsole.width - sizes.width) / 2;
	topLeftPosition.y = (sizeConsole.height - sizes.height) / 2;
	return topLeftPosition;
}

void Window::PrintOutline(Position_XY coordinate)
{
	ConsoleController curcore;
	for (int i = 0; i < sizes.height; i++)
	{
		curcore.SetCursorPosition(coordinate);
		for (int j = 0; j < sizes.width; j++)
		{
			if (i == 0 || i == sizes.height - 1 ||
				j == 0 || j == sizes.width  - 1) cout << '#';
			else cout << ' ';
		}
		coordinate.y++;
	}
}

void Window::Print(Position_XY coordinate)
{
	ConsoleController curcore;
	curcore.SetCursorPosition(coordinate);
	for (int i = 0; text[i] != '\0'; i++)
	{
		if (text[i] == '\n')
		{
			coordinate.y++;
			curcore.SetCursorPosition(coordinate);
			continue;
		}
		cout << text[i];
	}
}
