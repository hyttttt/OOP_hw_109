#include "Atoi.h"

// Intent: Default constructor of class Atoi
// Pre: No input needed
// Post: Set the beTrans(string) to be an empty string
Atoi::Atoi()
{
	this->beTrans = "";
}

// Intent: Copy constructor of class Atoi
// Pre: Input a string
// Post: Set the beTrans(string) to be the input string
Atoi::Atoi(string s)
{
	this->beTrans = s;
}

// Intent: Set the beTrans(string) to be the input string
// Pre: Input a string
// Post: The input string becomes beTrans(string)
void Atoi::SetString(string s)
{
	this->beTrans = s;
}

// Intent: Access beTrans(string)
// Pre: No input needed
// Post: Return beTrans(string)
const string Atoi::GetString()
{
	return this->beTrans;
}

// Intent: Get how many digits there are in beTrans(string)
// Pre: No input needed
// Post: Return the number of digits
int Atoi::Length()
{
	if (this->beTrans[0] != '-')
	{
		return this->beTrans.size();
	}
	else
	{
		return this->beTrans.size() - 1;
	}
}

// Intent: Determine whether beTrans contains non-number
// Pre: No input needed
// Post: Return true when it doesn't contain non-number, otherwise return false
bool Atoi::IsDigital()
{
	for (int i = 0; i < this->beTrans.size(); i++)
	{
		if (this->beTrans[0] == '-')
		{
			continue;
		}
		if ((this->beTrans[i] - '0') < 0 || (this->beTrans[i] - '0') > 9)
		{
			return false;
		}
	}

	return true;
}

// Intent: Convert beTrans(string) into integer
// Pre: No input needed
// Post: Return the converted integer
int Atoi::StringToInteger()
{
	int result = 0;

	if (this->beTrans[0] != '-')
	{
		//start from the last digit
		for (int i = this->beTrans.size() - 1, digit = 1; i >= 0; i--, digit *= 10)
		{
			result += (this->beTrans[i] - '0') * digit;
		}
	}
	else
	{
		//start form the last digit
		for (int i = this->beTrans.size() - 1, digit = 1; i > 0; i--, digit *= 10)
		{
			result += (this->beTrans[i] - '0') * digit;
		}

		result *= -1;
	}

	return result;
}