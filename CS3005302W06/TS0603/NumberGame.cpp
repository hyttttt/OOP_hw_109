#include "NumberGame.h"
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>

// Intent: To set up the value of number A
// Pre: Input a integer that will be the value of number A
// Post: Set the number A as the input integer
void NumberGame::SetInput(int input)
{
	this->a = input;
}

// Intent: To split each digit of the number A
// Pre: No input needed
// Post: Store each digit in the vector aDigits
void NumberGame::ProcessInput(void)
{
	std::vector<int>::iterator it;

	while (this->a != 0)
	{
		int digit = a % 10;
		this->aDigits.push_back(digit);
		this->a /= 10;
	}

	for (int i = 0; i < aDigits.size(); i++)
	{
		check.push_back(false);
	}
}

// Intent: To set up the file name
// Pre: Input a string that will be the name of file
// Post: Set the file name as the input string
void NumberGame::SetFileName(std::string name)
{
	this->fileName = name;
}

// Intent: To open a file and read the number list in it
// Pre: file name must be set up already
// Post: Store the numbers in the vector S
void NumberGame::LoadNumberList(void)
{
	std::ifstream inputS;
	long long int num;

	inputS.open(this->fileName);
	while (inputS >> num)
	{
		this->s.push_back(num);
	}
	inputS.close();
}

// Intent: To print all the corresponding numbers in S
// Pre: A must be split into digits in aDigits
// Post: print out the result
void NumberGame::PrintAllValid()
{
	//calculate all the possible multiplication of each digit
	for (int i = 0; i <= aDigits.size(); i++)
	{
		Combi(aDigits, i, 0, 0, check, aDigits.size());
	}

	//store the corresponding numbers in S into vector valid
	for (int i = 0; i < s.size(); i++)
	{
		std::vector<int>::iterator it = find(combination.begin(), combination.end(), s[i]);

		if (it != combination.end())
		{
			valid.push_back(s[i]);
		}
	}

	//arrange the valid numbers in ascending order
	std::sort(valid.begin(), valid.end());

	//print out the result
	for (int i = 0; i < valid.size(); i++)
	{
		std::cout << valid[i] << std::endl;
	}
}

// Intent: To erase all the stored value
// Pre: No input needed
// Post: All variables are empty
void NumberGame::Reset(void)
{
	this->a = 0;
	this->fileName = " ";
	this->aDigits.erase(this->aDigits.begin(), this->aDigits.end());
	this->s.erase(this->s.begin(), this->s.end());
	this->check.erase(this->check.begin(), this->check.end());
	this->combination.erase(this->combination.begin(), this->combination.end());
	this->valid.erase(this->valid.begin(), this->valid.end());
}

// Intent: To find all the possible multiplication of each digit recursively
// Pre: Must input where to start and where to end
// Post: Store all possible multiplication in vector combination
void NumberGame::Combi(std::vector<int>splitDigit, int reqLen, int start, int currLen, std::vector<bool>check, unsigned int length)
{
	if (currLen > reqLen)
		return;
	else if (currLen == reqLen)
	{
		int tmp = 1;
		bool loopExecute = false;

		//multiplication
		for (int i = 0; i < length; i++)
		{
			if (check[i] == true)
			{
				tmp *= splitDigit[i];
				loopExecute = true;
			}
		}
		if (loopExecute)
		{
			combination.push_back(tmp);
		}
		return;
	}
	if (start == length)
	{
		return;
	}

	//recurse
	check[start] = true;
	Combi(splitDigit, reqLen, start + 1, currLen + 1, check, length);
	check[start] = false;
	Combi(splitDigit, reqLen, start + 1, currLen, check, length);
}