#include "Container/Stack.h"
#include "Location2D.h"

#include <iostream>
#include <Windows.h> // 콘솔 제어를 위해 활용.

// Direction. 
// Order to add: up => down => left => right
// Order could be arranged by the programmer's mind.
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };


// 맵 (미로).
// 작은 맵.
//const int mazeSize = 6;
//char map[mazeSize][mazeSize] =
//{
//	{'1','1','1','1','1','1'},
//	{'e','0','1','0','0','1'},
//	{'1','0','0','0','1','1'},
//	{'1','0','1','0','1','1'},
//	{'1','0','1','0','0','x'},
//	{'1','1','1','1','1','1'}
//};

// 큰 맵.
const int mazeSize = 20;
char map[mazeSize][mazeSize] =
{
	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1'},
	{'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
	{'1', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
	{'1', '0', '1', '0', '1', '0', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1'},
	{'1', '0', '0', '0', '1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
	{'1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1'},
	{'e', '0', '1', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
	{'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1', '1', '1', '0', '1'},
	{'1', '0', '1', '0', '0', '0', '0', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
	{'1', '0', '1', '0', '1', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
	{'1', '0', '0', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '1', '0', '1', '0', '1', '1', '1', '0', '1', '1', '1', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
	{'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', 'x'},
	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
};

// Check if the position to visit is valid.
bool isValidLocation(const Location2D& location)
{
	// For convenience.
	const int row = location.row;
	const int col = location.col;

	// Check the range of the index.
	if (row < 0 || row >= mazeSize || col < 0 || col >= mazeSize)
	{
		return false;
	}

	// Check.
	return map[row][col] == '0' || map[row][col] == 'x';
}

// Clear the Screen of the console.
void ClearScreen()
{
	// console command clearscreen.
	system("cls");
}

// Set Text Colour.
void SetConsoleColor(WORD color)
{
	SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE),
		color
	);
}


// Draw the Map.
void PrintMap(const Location2D& playerPosition, DWORD delay)
{
	// Stop Thread until delay(unit: millisecond => second/1000).
	Sleep(delay);

	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);

	// Draw Rounding the map.
	for (int row = 0; row < mazeSize; ++row)
	{
		for (int col = 0; col < mazeSize; ++col)
		{
			// Print player.
			if (row == playerPosition.row &&
				col == playerPosition.col)
			{
				SetConsoleColor(FOREGROUND_GREEN);
				std::cout << "P ";
				SetConsoleColor(
					FOREGROUND_BLUE
					| FOREGROUND_GREEN
					| FOREGROUND_RED
				);
				continue;
			}

			// Print target position.
			if(map[row][col]=='x')
			{
				SetConsoleColor(FOREGROUND_RED);
				std::cout << "X ";
				SetConsoleColor(
					FOREGROUND_BLUE
					| FOREGROUND_GREEN
					| FOREGROUND_RED
				);
				continue;
			}

			// Print normal map item.
			std::cout << map[row][col] << " ";
		}
		std::cout << "\n";
	}
}



int main()
{
	// Turn off the cursor.
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 1;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&info
	);

	// Search the start position.
	Location2D start;

	bool found = false;
	for (int row = 0; row < mazeSize; ++row)
	{
		for (int col = 0; col < mazeSize; ++col)
		{
			// Search the start position character.
			if (map[row][col] == 'e')
			{
				start.row = row;
				start.col = col;
				found = true;
				break;
			}
		}

		// If search is successed, Quit this loop.
		if (found)
		{
			break;
		}
	}

	// Print Initial Map.
	PrintMap(start, 0);

	// Create Stack.
	Stack<Location2D, mazeSize> stack;
	
	// Add start position to stack.
	stack.Push(start);

	// Use DFS to find path.
	// if stack is not empty == The position to visit is not empty.
	// Visit and Find the path.
	found = false;
	while (!stack.IsEmpty())
	{
		// Pop the position to visit.
		Location2D current;
		if (!stack.Pop(current))
		{
			break;
		}

		// Print the position with Animation-like effect.
		PrintMap(current, 500);

		// Check if it arrived to the exit.
		if (map[current.row][current.col] == 'x')
		{
			std::cout << "\n미로 탐색 성공\n";
			found = true;
			break;
		}

		// Else: Mark down the visited position.
		map[current.row][current.col] = '.';

		// Add next visit position to the stack.
		for (int ix = 0; ix < 4; ++ix)
		{
			if (isValidLocation(Location2D(current.row + dy[ix], current.col + dx[ix])))
			{
				stack.Push(Location2D(current.row + dy[ix], current.col + dx[ix]));
			}
		}
	}

	if (!found) std::cout << "\n미로 탐색 실패!\n";

	return 0;
}