#include "Fraction.h"

void Fraction::setNumerator(int nu)
{
	this->numerator = nu;
}

void Fraction::setDenominator(int de)
{
	this->denominator = de;
}

void Fraction::getDouble()
{
	double dbFraction = (double)this->numerator / (double)this->denominator;
	int intFraction = (int)dbFraction;
	if (dbFraction - intFraction == 0.0)
	{
		std::cout << intFraction << std::endl;
	}
	else
	{
		std::cout << std::fixed << std::setprecision(6) << dbFraction << std::endl;
	}
}

void Fraction::outputReducedFraction()
{
	int numer = this->numerator, deno = this->denominator, remainder;

	//the result can be represented in integer
	if (this->numerator % this->denominator == 0)
	{
		std::cout << this->numerator / this->denominator << std::endl;
	}

	else
	{
		//find gcd, numer will be the gcd
		while (deno != 0)
		{
			remainder = numer % deno;
			numer = deno;
			deno = remainder;
		}

		std::cout << this->numerator / numer << "/" << this->denominator / numer << std::endl;
	}
}



