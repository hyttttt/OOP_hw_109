#include "HotDogStand.h"
#include <iostream>

using namespace std;

int HotDogStand::totalSellAmount = 0;

// Intent: This function is the default constructor of class Month
// Pre: This function doesn't need input
// Post: This function doesn't return anything
HotDogStand::HotDogStand() {}

// Intent: This function is the destructor of class Month
// Pre: This function doesn't need input
// Post: This function doesn't return anything
HotDogStand::~HotDogStand() {}

// Intent: This function is the constructor of class HotDogStand
// Pre: The input char[] would be the stand id
// Post: The stand id is set as the input char[]
HotDogStand::HotDogStand(const char* id)
{
	standId = const_cast<char*>(id);
	this->hotDogSellAmount = 0;
}

// Intent: This function is the constructor of class HotDogStand
// Pre: The input char array is the stand id, int amount is the sold amount
// Post: The stand id is set as the input char[], and sold amount is set as the input int amount
HotDogStand::HotDogStand(const char* id, int amount)
{
	standId = const_cast<char*>(id);
	this->hotDogSellAmount = amount;
	totalSellAmount += amount;
}

// Intent: To add 1 to the sold amount and total amount
// Pre: This function doesn't need input
// Post: The sold amount and total amount are added 1, no return value
void HotDogStand::justSold()
{
	this->hotDogSellAmount++;
	totalSellAmount++;
}

// Intent: To print out the stand id and its sold amount
// Pre: This function doesn't need input
// Post: Print out the stand id and its sold amount, no return value
void HotDogStand::print()
{
	std::cout << this->standId << ' ' << this->hotDogSellAmount << std::endl;
}

// Intent: To return the sold amount of the stand
// Pre: This function doesn't need input
// Post: Return the sold amount of the stand
int HotDogStand::thisStandSoldAmount()
{
	return this->hotDogSellAmount;
}
