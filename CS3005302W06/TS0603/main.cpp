// Name: ½²´ð¼ü
// Date:  April 6, 2021
// Last Update: April 6, 2021
// Problem statement: This C++ program is a number game, in which we calculate all the possible multiplication of each digit of the number A,
//						and find the corresponding ones in the list S

#include <iostream>
#include "NumberGame.h"
using namespace std;
int main() {
	NumberGame Game;
	Game.SetInput(1234);
	Game.ProcessInput();
	Game.SetFileName("number.txt");
	Game.LoadNumberList();
	Game.PrintAllValid();

	Game.Reset();
	cout << "\n";
	Game.SetInput(2345);
	Game.ProcessInput();
	Game.SetFileName("number.txt");
	Game.LoadNumberList();
	Game.PrintAllValid();

}