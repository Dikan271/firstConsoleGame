#include "Game.h"

Game::Game() 
{
	windowIsOpen = 0;
}

void Game::SetLocation(string startLocation)
{
	location.SetLocation(startLocation);
}

void Game::StartGame()
{
	ConsoleController cursore;
	cursore.DeleteCursor();
	Position_XY startPosition = GetStartHiroPosition();
	hiro.SetPosition(startPosition);
	location.Print();
	Print();
}

Position_XY Game::GetStartHiroPosition()
{
	bool isWall;
	srand(unsigned(time(0)));
	Dimensions sizeLocation = location.GetSize();
	Position_XY tempPosition;
	do
	{
		tempPosition.x = rand() % sizeLocation.width;
		tempPosition.y = rand() % sizeLocation.height;
		isWall = location.CheckWall(tempPosition);
	} while (isWall);
	return tempPosition;
}

void Game::Print()
{
	if (windowIsOpen) return;
	static Item previous = ' ';
	Position_XY hiroPosition = hiro.GetPosition();
	char formObject = hiro.Get_Form();
	PrintMoveObject(hiroPosition, previous, formObject);
	previous = location.GetItem(hiroPosition);
}

void Game::PrintMoveObject(Position_XY position, Item previous, char objectForMove)
{
	ConsoleController goPOsitionCursor;
	std::cout << previous;
	goPOsitionCursor.SetCursorPosition(position);
	std::cout << objectForMove;
	goPOsitionCursor.SetCursorPosition(position);
}

bool Game::Control()
{
	if (!_kbhit())
		return 0;
	int key = _getch();
	bool isCommand = keyboard::IsCommand(key);
	bool isDirection = keyboard::IsDirection(key);
	if (isCommand)
		CommandManager(key);
	else if (isDirection && windowIsOpen == 0)
	{
		MoveObject(key, &hiro);
		TakeItem(&hiro);
	}
	return 0;
}

Window testWin;
void Game::CommandManager(int key)
{
	switch (key)
	{
	case Command::command_STOP:  EndGame(); break;
	case Command::command_TEST:  
	{
		if (testWin.IsOpen()) 
		{
			testWin.Close();
			windowIsOpen--;
			break;
		}
		testWin.SetText("one one one\n it is hardbass\nall in buts from addidas");
		testWin.Open();
		windowIsOpen++;
		break;
	}
	case Command::command_PAUSE: CallMenu(&hiro); break;
	case Command::command_ENTER: break;
	}
}

void Game::MoveObject(int key, Mob* moveMan)
{
	Direction direction = keyboard::GetDirection(key);
	bool iCanMove = SeeIfICanMove(direction, moveMan);
	if (iCanMove)
		moveMan->Move(direction);
}

void Game::EndGame()
{
	if (menu.IsOpen())
		CloseMenu();
	Window gameOver("file/endGame.txt");
	ConsoleController setOutputColor;
	setOutputColor.SetColor(4);
	gameOver.Open();
	_getch(); _getch();
	gameOver.Close();
	exit(0);
}

void Game::CallMenu(Mob* masterOfInventory)
{
	if (!menu.IsOpen())
		 OpenMenu(masterOfInventory);
	else CloseMenu();
}

void Game::OpenMenu(Mob * masterOfInventory)
{
	Inventory bagMan = masterOfInventory->GetInventory();
	menu.SetINventory(&bagMan);
	menu.Open();
	windowIsOpen++;
}

void Game::CloseMenu()
{
	menu.Close(); 
	ConsoleController goPOsitionCursor;
	Position_XY xy;
	xy.x = xy.y = 0;
	goPOsitionCursor.SetCursorPosition(xy);
	location.Print();
	Print();
	windowIsOpen--;
}

bool Game::SeeIfICanMove(Direction direction, Mob* moveMan)
{
	Position_XY positionOfPerson = moveMan->GetPosition();
	iMove test(positionOfPerson);
	Position_XY newPosition = test.Move(direction);
	bool isWall = location.CheckWall(newPosition);
	return !isWall;
}

void Game::TakeItem(Player * masterOfInventory)
{
	Position_XY positionOfPerson = masterOfInventory->GetPosition();
	Item item = location.GetItem(positionOfPerson);
	bool thisCellIsEmpty = item.GetCounter() == 0;
	if (thisCellIsEmpty)
		return;
	masterOfInventory->Take(item);//todo her
}
