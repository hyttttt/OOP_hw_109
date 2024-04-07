#include "School.h"
#include <iostream>

/*School*/

// Intent: Default constructor of class School
// Pre: No input needed
// Post: All members are 0 or empty string
School::School()
{
	this->name = "";
	this->studentAmount = 0;
	this->studentAmountNextYear = 0;
}

// Intent: Constructor of class School
// Pre: Input the name of the school and the amount of the student
// Post: All members are set to be the corresponding value
School::School(std::string name, int amount)
{
	this->name = name;
	this->studentAmount = amount;
	this->studentAmountNextYear = amount;
}

// Intent: Increase the number of students
// Pre: Input the number of admissions
// Post: The number of the students increases
void School::admissions(int amount)
{
	if (amount > 0)
	{
		this->studentAmount += amount;
	}
}

// Intent: Decrease the number of the students
// Pre: Input the number of the dropouts
// Post: The number of the students decreases
void School::dropouts(int amount)
{
	if (amount > 0 && amount <= this->studentAmount)
	{
		this->studentAmount -= amount;
	}
}

// Intent: Transfer students from one school to another
// Pre: Input the number of students that will be transfered and the destined school
// Post: The number of students decreases, and the the number of students in the destined school increases
void School::transfer(int amount, School& toSchool)
{
	if (amount > 0 && amount <= this->studentAmount)
	{
		this->dropouts(amount);
		toSchool.admissions(amount);
	}
}

// Intent: Overload the output operator for class School
// Pre: Input the output stream and School object
// Post: Put the value in the output stream
std::ostream& operator<<(std::ostream& ostrm, const School& school)
{
	ostrm << school.name << '\t'
		<< school.studentAmount << '\t'
		<< school.studentAmountNextYear;

	return ostrm;
}

/*PublicSchool*/

// Intent: Default constructor of class PubilcSchool
// Pre: No input needed
// Post: All members are 0 or empty string, except for the growing_rate being 0.05
PublicSchool::PublicSchool() :School()
{
	this->growing_rate = 0.05;
}

// Intent: Constructor of class PublicSchool
// Pre: Input the name of the school and the amount of the student
// Post: All members are set to be the corresponding value
PublicSchool::PublicSchool(std::string name, int amount) : School(name, amount)
{
	this->growing_rate = 0.05;
}

// Intent: Caculate the number of the student next year with the growing rate
// Pre: No input needed
// Post: The number of the students next year increases
void PublicSchool::apply_growth()
{
	double next = this->studentAmountNextYear;
	double rate = this->growing_rate;
	next += rate * next;
	this->studentAmountNextYear = (int)next;
}

// Intent: Decrease the number of the students with penalties when over 100 students dropout at once
// Pre: Input the number of the dropouts
// Post: The number of the students decreases
void PublicSchool::dropouts(int amount)
{
	if (amount > 0 && amount <= this->studentAmount)
	{
		this->studentAmount -= amount;

		if (amount > 100)
		{
			double next = this->studentAmountNextYear;
			next *= 0.95;
			this->studentAmountNextYear = (int)next;
		}
	}
}

/*PrivateSchool*/

int PrivateSchool::wave = 0;

// Intent: Default constructor of class PrivateSchool
// Pre: No input needed
// Post: All members are 0 or empty string
PrivateSchool::PrivateSchool() :School() {};

// Intent: Constructor of class PrivateSchool
// Pre: Input the name of the school and the amount of the student
// Post: All members are set to be the corresponding value
PrivateSchool::PrivateSchool(std::string name, int amount) : School(name, amount) {};

// Intent: Decrease the number of the students with penalties when over one wave of students dropout
// Pre: Input the number of the dropouts
// Post: The number of the students decreases
void PrivateSchool::dropouts(int amount)
{
	if (amount > 0 && amount <= this->studentAmount)
	{
		this->studentAmount -= amount;
		this->wave++;

		if (wave != 1)
		{
			this->studentAmountNextYear -= 100;
		}
	}
}