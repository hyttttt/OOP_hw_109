// Name: ½²´ð¼ü
// Date:  April 20, 2021
// Last Update: April 20, 2021
// Problem statement: It is a tile-matching game, Shisensho, that intends to find match pairs

#include <iostream>
#include <cmath>

int board[8][8] = { 0 };

// Intent: To check whether the straight road between two points is clear
// Pre: Inputs are coordinate of two points, and the road between them must be straight
// Post: Return true when the road is clear, otherwise return false
bool findClearRoad(int x1, int y1, int x2, int y2)
{
	int sum = 0;

	//when they are next to each other, return true
	if (abs(x1 - x2) + abs(y1 - y2) == 1)
	{
		return true;
	}

	//Vertical road
	if (x1 == x2)
	{
		sum = 0;
		for (int i = std::min(y1, y2) + 1; i < std::max(y1, y2); i++)
		{
			sum += board[i][x1];
		}

		if (sum == 0)
		{
			return true;
		}
	}
	

	//Horizontal road
	if (y1 == y2)
	{
		sum = 0;
		for (int i = std::min(x1, x2) + 1; i < std::max(x1, x2); i++)
		{
			sum += board[y1][i];
		}

		if (sum == 0)
		{
			return true;
		}
	}

	return false;
}

// Intent: To check whether two tiles matches and whether the route is valid
// Pre: Inputs are coordinate of two points
// Post: Return true for matched tiles and valid route, otherwise return false
bool checkValid(int x1,int y1,int x2,int y2)
{
	if (board[y1][x1] != board[y2][x2] //different symbols
		|| board[y1][x1] == 0 //They are both empty
		|| (x1 == x2 && y1 == y2)) //They are the same point
	{
		return false;
	}

	/*next to each other*/
	if (findClearRoad(x1, y1, x2, y2))
	{
		return true;
	}

	/*take one turn*/
	if (board[y2][x1] == 0 && (findClearRoad(x1, y1, x1, y2) && findClearRoad(x1, y2, x2, y2)) //The corner is (x1, y2)
		|| (board[y1][x2] == 0 && findClearRoad(x1, y1, x2, y1) && findClearRoad(x2, y1, x2, y2))) //The corner is (x2, y1)
	{
		return true;
	}

	/*take two turns*/
	//Position of two corners are vertical
	for (int i = 0; i < 8; i++)
	{
		if (board[y1][i] == 0 && board[y2][i] == 0)
		{
			if (findClearRoad(x1, y1, i, y1) && findClearRoad(i, y1, i, y2) && findClearRoad(i, y2, x2, y2))
			{
				return true;
			}
		}
	}

	//Position of two corners are horizontal
	for (int i = 0; i < 8; i++)
	{
		if (board[i][x1] == 0 && board[i][x2] == 0)
		{
			if (findClearRoad(x1, y1, x1, i) && findClearRoad(x1, i, x2, i) && findClearRoad(x2, i, x2, y2))
			{
				return true;
			}
		}
	}

	return false;
}

int main()
{
	for (int i = 1; i < 7; i++)
	{
		for (int j = 1; j < 7; j++)
		{
			std::cin>>board[i][j];
		}
	}

	int x1, y1, x2, y2;
	while (std::cin >> x1 >> y1 >> x2 >> y2)
	{
		//adjust the coordinate
		x1++;	y1++;
		x2++;	y2++;

		if (checkValid(x1, y1, x2, y2))
		{
			std::cout << "pair matched" << std::endl;
			board[y1][x1] = 0;
			board[y2][x2] = 0;
		}
		else
		{
			std::cout << "bad pair" << std::endl;
		}
	}
}