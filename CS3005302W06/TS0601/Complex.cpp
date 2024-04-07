#include "Complex.h"
#include <math.h>

// Intent: Default constructor of calss Complex
// Pre: No input needed
// Post: Set both parts as 0
Complex::Complex()
{
	this->realValue = 0.0;
	this->imaginaryValue = 0.0;
}

// Intent: A constructor of calss Complex
// Pre: Input r to be real part
// Post: Set real part as r, imaginary part as 0
Complex::Complex(double r)
{
	this->realValue = r;
	this->imaginaryValue = 0.0;
}

// Intent: A constructor of calss Complex
// Pre: Input r to be real part, i to be imaginary part
// Post: Set real part as r, imaginary part as i
Complex::Complex(double r, double i)
{
	this->realValue = r;
	this->imaginaryValue = i;
}

// Intent: To return the real part
// Pre: No input needed
// Post: Return the real part
double Complex::real()
{
	return this->realValue;
}

// Intent: To return the imaginary part
// Pre: No input needed
// Post: Return the imaginary part
double Complex::imag()
{
	return this->imaginaryValue;
}

// Intent: To return the norm
// Pre: No input needed
// Post: Return the norm
double Complex::norm()
{
	double norm;
	norm = pow(this->realValue, 2.0) + pow(this->imaginaryValue, 2.0);
	norm = sqrt(norm);
	return norm;
}

// Intent: To return the real part of c
// Pre: Input a complex number c
// Post: Return the real part of c
double real(Complex c)
{
	return c.realValue;
}

// Intent: To return the imaginary part of c
// Pre: Input a complex number c
// Post: Return the imaginary part of c
double imag(Complex c)
{
	return c.imaginaryValue;
}

// Intent: To return the norm of c
// Pre: Input a complex number c
// Post: Return the norm of c
double norm(Complex c)
{
	double norm;
	norm = pow(c.realValue, 2.0) + pow(c.imaginaryValue, 2.0);
	norm = sqrt(norm);
	return norm;
}

// Intent: Overloading operator "+" to plus two complex numbers together
// Pre: Input a complex number c to be added
// Post: Return the sum of them
Complex Complex::operator+(Complex c)
{
	Complex add;
	add.realValue = this->realValue + c.realValue;
	add.imaginaryValue = this->imaginaryValue + c.imaginaryValue;
	return add;
}

// Intent: Overloading operator "-" to subtract a complex number from the previous one
// Pre: Input a complex number c to subtract
// Post: Return the result of subtraction
Complex Complex::operator-(Complex c)
{
	Complex minus;
	minus.realValue = this->realValue - c.realValue;
	minus.imaginaryValue = this->imaginaryValue - c.imaginaryValue;
	return minus;
}

// Intent: Overloading operator "*" to multiply two complex numbers
// Pre: Input a complex number c to multiply
// Post: Return the result of multiplication
Complex Complex::operator*(Complex c)
{
	Complex times;
	times.realValue = this->realValue * c.realValue - this->imaginaryValue * c.imaginaryValue;
	times.imaginaryValue = this->realValue * c.imaginaryValue + this->imaginaryValue * c.realValue;
	return times;
}

// Intent: Overloading operator "/" to divide two complex numbers
// Pre: Input a complex number c to divide
// Post: Return the result of division
Complex Complex::operator/(Complex c)
{
	Complex divide;

	//calculate (a + bi) / (c + di) 
	//real part = (a*c + b*d) / (c^2 + d^2)
	//imaginary part = (b*c - a*d) / (c^2 + d^2)
	divide.realValue = (this->realValue * c.realValue + this->imaginaryValue * c.imaginaryValue) / (pow(c.realValue, 2.0) + pow(c.imaginaryValue, 2.0));
	divide.imaginaryValue = (this->imaginaryValue*c.realValue -this->realValue*c.imaginaryValue)/ (pow(c.realValue, 2.0) + pow(c.imaginaryValue, 2.0));
	
	return divide;
}

// Intent: Overloading operator "+" to add a real number with a complex number
// Pre: Input a complex number c and a real number d
// Post: Return the sum of them
Complex operator+(double d, Complex c)
{
	Complex add;
	add.realValue = d + c.realValue;
	add.imaginaryValue = c.imaginaryValue;
	//std::cout << "called friend plus" << std::endl;
	return add;
}

// Intent: Overloading operator "-" to subtract a complex number from the real number d
// Pre: Input a complex number c to subtract, and a real number d to be subtracted
// Post: Return the result of subtraction
Complex operator-(double d, Complex c)
{
	Complex minus;
	minus.realValue = d - c.realValue;
	minus.imaginaryValue = -c.imaginaryValue;
	return minus;
}

// Intent: Overloading operator "*" to multiply two a complex number and a real number d
// Pre: Input a complex number c and a real number d to multiply
// Post: Return the result of multiplication
Complex operator*(double d, Complex c)
{
	Complex times;
	times.realValue = d * c.realValue;
	times.imaginaryValue = d * c.imaginaryValue;
	return times;
}

// Intent: Overloading operator "/" to divide a real number with a complex number
// Pre: Input a complex number c to divide, and a real number to be divided
// Post: Return the result of division
Complex operator/(double d, Complex c)
{
	Complex divide;

	//calculate (a + bi) / (c + di) 
	//real part = (a*c + b*d) / (c^2 + d^2)
	//imaginary part = (b*c - a*d) / (c^2 + d^2)
	divide.realValue = d * c.realValue / (pow(c.realValue, 2.0) + pow(c.imaginaryValue, 2.0));
	divide.imaginaryValue = (-d * c.imaginaryValue) / (pow(c.realValue, 2.0) + pow(c.imaginaryValue, 2.0));

	return divide;
}

// Intent: Overloading operator "==" to check if two complex numbers are the same
// Pre: Input two complex number to compare
// Post: Return true for two same complex numbers, otherwise return false
bool operator==(Complex c1, Complex c2)
{
	if (c1.realValue == c2.realValue && c1.imaginaryValue == c2.imaginaryValue)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Intent: To check if the double can be represented with a integer
// Pre: Input a double type number
// Post: Return true when it can be represented with a integer, otherwise return false
bool checkInt(double douNum)
{
	int intNum = (int)douNum;
	if (douNum - (double)intNum == 0.0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Intent: Overloading operator "<<" to make complex number represents as form "a + bi"
// Pre: Input a complex number c which need to represent with the form "a + bi", and a ostream to store the output
// Post: Return the ostream where we store a complex number with the form "a + bi"
ostream& operator<<(ostream& strm, const Complex& c)
{
	if (checkInt(c.realValue))
	{
		strm << (int)c.realValue << " + ";
	}
	else
	{
		strm << c.realValue << " + ";
	}

	if (checkInt(c.imaginaryValue))
	{
		strm << (int)c.imaginaryValue << "*i";
	}
	else
	{
		strm << c.imaginaryValue << "*i";
	}

	return strm;
}

// Intent: Overloading operator "<<" to get a complex number represents, which is inputed with the form "c = a + bi"
// Pre: Input a complex number c where the information are stored, and istream where we get the iniformation
// Post: Return the istream
istream& operator>>(istream& strm, Complex& c)
{
	char none1, none2, none3;
	std::string none;

	strm >> none1; //store the name of complex number
	strm >> none2; //store the "="
	strm >> c.realValue;
	strm >> none3; //store the "+"
	strm >> c.imaginaryValue;
	strm >> none; //store "i"

	return strm;
}