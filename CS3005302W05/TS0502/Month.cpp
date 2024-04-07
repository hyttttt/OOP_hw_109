#include "Month.h"
#include <iostream>
#include <string>

using namespace std;

// Intent: This function is the destructor of class Month
// Pre: This function doesn't need input
// Post: This function doesn't return anything
Month::~Month() {}

// Intent: This function is the default constructor of class Month
// Pre: This function doesn't need input
// Post: The default month is set to be 1
Month::Month()
{
	this->month = 1;
}

// Intent: This function is a constructor of class Month
// Pre: The input characters are abbreviation of a month
// Post: The month is set to be the corresponding month for the input abbreviation
Month::Month(char first, char second, char third)
{
	if (first == 'J' && second == 'a' && third == 'n') //January
	{
		this->month = 1;
	}
	else if (first == 'F' && second == 'e' && third == 'b')	//February
	{
		this->month = 2;
	}
	else if (first == 'M' && second == 'a' && third == 'r')	//March
	{
		this->month = 3;
	}
	else if (first == 'A' && second == 'p' && third == 'r')	//April
	{
		this->month = 4;
	}
	else if (first == 'M' && second == 'a' && third == 'y')	//May
	{
		this->month = 5;
	}
	else if (first == 'J' && second == 'u' && third == 'n')	//June
	{
		this->month = 6;
	}
	else if (first == 'J' && second == 'u' && third == 'l') //July
	{
		this->month = 7;
	}
	else if (first == 'A' && second == 'u' && third == 'g') //August
	{
		this->month = 8;
	}
	else if (first == 'S' && second == 'e' && third == 'p')	//September
	{
		this->month = 9;
	}
	else if (first == 'O' && second == 'c' && third == 't')	//October
	{
		this->month = 10;
	}
	else if (first == 'N' && second == 'o' && third == 'v')	//November
	{
		this->month = 11;
	}
	else if (first == 'D' && second == 'e' && third == 'c')	//December
	{
		this->month = 12;
	}
}

// Intent: This function is a constructor of class Month
// Pre: The input int must be a number between 1 and 12 and represents a month
// Post: The month is set to be the corresponding month for the input int
Month::Month(int monthInt)
{
	this->month = monthInt;
	if (this->month > 12)
		this->month = 1;
}

// Intent: To set the month as the input
// Pre: This function doesn't need input
// Post: The month is set as the input, no return value
void Month::inputInt()
{
	int x;
	std::cin >> x;
	switch (x)
	{
	case 1:
		this->month = 1;
		break;
	case 2:
		this->month = 2;
		break;
	case 3:
		this->month = 3;
		break;
	case 4:
		this->month = 4;
		break;
	case 5:
		this->month = 5;
		break;
	case 6:
		this->month = 6;
		break;
	case 7:
		this->month = 7;
		break;
	case 8:
		this->month = 8;
		break;
	case 9:
		this->month = 9;
		break;
	case 10:
		this->month = 10;
		break;
	case 11:
		this->month = 11;
		break;
	case 12:
		this->month = 12;
		break;
	default:
		this->month = 1;
	}
}

// Intent: To set the month as the corrresponding month for the input abbreviation
// Pre: The input characters are abbreviation of a month
// Post: The month is set to be the corresponding month for the input abbreviation, no return value
void Month::inputStr()
{
	char first, second, third;
	std::cin >> first >> second >> third;

	if (first == 'J' && second == 'a' && third == 'n')	//January
	{
		this->month = 1;
	}
	else if (first == 'F' && second == 'e' && third == 'b')	//February
	{
		this->month = 2;
	}
	else if (first == 'M' && second == 'a' && third == 'r')	//March
	{
		this->month = 3;
	}
	else if (first == 'A' && second == 'p' && third == 'r')	//April
	{
		this->month = 4;
	}
	else if (first == 'M' && second == 'a' && third == 'y')	//May
	{
		this->month = 5;
	}
	else if (first == 'J' && second == 'u' && third == 'n')	//June
	{
		this->month = 6;
	}
	else if (first == 'J' && second == 'u' && third == 'l')	//July
	{
		this->month = 7;
	}
	else if (first == 'A' && second == 'u' && third == 'g')	//August
	{
		this->month = 8;
	}
	else if (first == 'S' && second == 'e' && third == 'p')	//September
	{
		this->month = 9;
	}
	else if (first == 'O' && second == 'c' && third == 't')	//October
	{
		this->month = 10;
	}
	else if (first == 'N' && second == 'o' && third == 'v')	//November
	{
		this->month = 11;
	}
	else if (first == 'D' && second == 'e' && third == 'c')	//December
	{
		this->month = 12;
	}
}

// Intent: To print out the month with int
// Pre: This function doesn't need input
// Post: Print out the month with int, no return value
void Month::outputInt()
{
	std::cout << this->month;
}

// Intent: To print out the month with abbreviation
// Pre: This function doesn't need input
// Post: Print out the month with abbreviation, no return value
void Month::outputStr()
{
	std::string abb;
	switch (this->month)
	{
	case 1:
		abb = "Jan";
		break;
	case 2:
		abb = "Feb";
		break;
	case 3:
		abb = "Mar";
		break;
	case 4:
		abb = "Apr";
		break;
	case 5:
		abb = "May";
		break;
	case 6:
		abb = "Jun";
		break;
	case 7:
		abb = "Jul";
		break;
	case 8:
		abb = "Aug";
		break;
	case 9:
		abb = "Sep";
		break;
	case 10:
		abb = "Oct";
		break;
	case 11:
		abb = "Nov";
		break;
	default:
		abb = "Dec";
	}

	std::cout << abb;
}

// Intent: To alter the month into the next month
// Pre: This function doesn't need input
// Post: Return the next month
Month Month::nextMonth()
{
	int next = this->month;
	next++;
	if (next > 12)
		next -= 12;

	return next;
}
