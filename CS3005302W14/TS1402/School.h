#pragma once
#ifndef SCHOOL_H
#define SCHOOL_H
#include <iostream>

class School
{
public:
	/*member*/
	std::string name;
	int studentAmount;
	int studentAmountNextYear;

	/*constructor*/
	School();
	School(std::string name, int amount);

	/*function*/
	void admissions(int amount);
	void virtual dropouts(int amount);
	void transfer(int amount, School& toSchool);

	/*operator overloading*/
	friend std::ostream& operator<<(std::ostream& ostrm, const School& school);
};

class PublicSchool :public School
{
public:
	/*member*/
	double growing_rate;

	/*consturctor*/
	PublicSchool();
	PublicSchool(std::string name, int amount);

	/*function*/
	void apply_growth();
	void dropouts(int amount);
};

class PrivateSchool :public School
{
public:
	/*member*/
	static int wave;

	/*constructor*/
	PrivateSchool();
	PrivateSchool(std::string name, int amount);

	/*function*/
	void dropouts(int amount);
};

#endif // !SCHOOL_H