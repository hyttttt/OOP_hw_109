#include "PrimeNumber.h"

// Intent: To check whether the input number is a prime number
// Pre: Input a integer
// Post: Return true when it is a prime number, otherwise return false
bool checkPrime(int input)
{
	/*First, make a list of prime numbers*/
	int index;
	bool prime[1000];
	int primeList[1000] = { 0 };
	
	//initialize prime with all true
	for (index = 0; index < 1000; index++)
	{
		prime[index] = true;
	}

	//0 and 1 are not prime numbers
	prime[0] = false;
	prime[1] = false;

	//filter the multiple of prime number to find all prime numbers less than 1000
	for (index = 0; index < 1000; index++)
	{
		if (prime[index])
		{
			for (int i = index * index; i < 1000; i += index)
			{
				prime[i] = false;
			}
		}
	}
	
	//make a list of all prime numbers less than 1000
	for (int i = 0, index = 0; index < 1000; index++)
	{
		if (prime[index])
		{
			primeList[i] = index;
			i++;
		}
	}

	/*Second, check if the input is a prime number*/
	for (int i = 0; i < 1000; i++)
	{
		if (input == primeList[i])
		{
			return true;
		}
	}

	return false;
}

// Intent: To access the value
// Pre: No input needed
// Post: Return the value of the prime number
int PrimeNumber::get()
{
	return this->value;
}

// Intent: Default constructor of calss PrimeNumber
// Pre: No input needed
// Post: Set value as 1
PrimeNumber::PrimeNumber()
{
	this->value = 1;
}

// Intent: Constructor of calss PrimeNumber
// Pre: Input a integer which will be the value
// Post: Set value as the input integer
PrimeNumber::PrimeNumber(int _value)
{
	this->value = _value;
}

// Intent: Overloading the operator "++" to find the next prime number
// Pre: No input needed
// Post: Return the next prime number
PrimeNumber& PrimeNumber::operator++() //prefix
{
	//keep increasing the value until we find the next prime number
	do
	{
		this->value++;
	} while (checkPrime(this->value) == false);

	return (*this);
}

// Intent: Overloading the operator "++" to find the next prime number
// Pre: No input needed
// Post: Return the next prime number
PrimeNumber PrimeNumber::operator++(int) //postfix
{
	PrimeNumber result = (*this);

	//keep increasing the value until we find the next prime number
	do
	{
		this->value++;
	} while (checkPrime(this->value) == false);

	return result;
}

// Intent: Overloading the operator "--" to find the last prime number
// Pre: No input needed
// Post: Return the last prime number
PrimeNumber& PrimeNumber::operator--() //prefix
{
	if (this->value == 2)
	{
		this->value--;
		return (*this);
	}
	else
	{
		//keep decreasing the value until we find the last prime number
		do
		{
			this->value--;
		} while (checkPrime(this->value) == false);

		return (*this);
	}
}

// Intent: Overloading the operator "--" to find the last prime number
// Pre: No input needed
// Post: Return the last prime number
PrimeNumber PrimeNumber::operator--(int) //postfix
{
	if (this->value == 2)
	{
		this->value--;
		return (*this);
	}
	else
	{
		PrimeNumber result = (*this);

		//keep decreasing the value until we find the last prime number
		do
		{
			this->value--;
		} while (checkPrime(this->value) == false);

		return result;
	}
}