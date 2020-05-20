#include "Item.h"

Item::Item()
{
	simbol = ' ';
	counter = 0;
}

Item::Item(char simbol)
{
	this->simbol = simbol;
	counter = simbol == ' '? 0 : 1;
}

int Item::GetCounter()
{
	return counter;
}

string Item::GetName()
{
	return ConvertNameToString();
}

void Item::SetItem(Item & object)
{
	this->simbol = object.simbol;
	this->counter = object.counter;
}

void Item::operator -= (int value)
{
	counter -= value;
}

void Item::operator+=(int value)
{
	counter += value;
}

string Item::ConvertNameToString()
{
	switch (simbol)
	{
	case ' ': return "       ";
	case '$': return "gold   ";
	case '*': return "star   ";
	case '@': return "shield ";
	case '&': return "meat   ";
	case '^': return "arrow  ";
	case '/': return "sword  ";
	case '%': return "powerUP";
	case '+': return "exp    ";
	case 'z': return "mn Mana";
	case 'Z': return "mx Mana";
	case 'x': return "mn HP  ";
	case 'X': return "mx HP  ";
	case 'T': return "bow    ";
	case '0': return "helmet ";
	default : return "unknow ";
	}
}

ostream & operator<<(ostream & os, Item dd)
{
	return os << dd.simbol;
}
