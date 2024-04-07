#pragma once
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <vector>

class Polynomial
{
public:
	/*member*/
	std::vector<double> coe;

	/*constructor*/
	Polynomial(){}
	Polynomial(double* param, int size);
	Polynomial(Polynomial& poly);

	/*member function*/
	int mySize();

	/*operator overloading*/
	Polynomial& operator=(const Polynomial& poly);
	double& operator[](int index);
	Polynomial operator+(Polynomial poly);
	Polynomial operator+(double num);
	Polynomial operator-(Polynomial poly);
	Polynomial operator-(double num);
	Polynomial operator*(Polynomial poly);
	Polynomial operator*(double num);
	friend Polynomial operator*(double num, Polynomial poly);
	friend Polynomial operator+(double num, Polynomial poly);
	friend Polynomial operator-(double num, Polynomial poly);

	/*friend function*/
	friend double evaluate(const Polynomial& poly, const double& var);
};

#endif // !POLYNOMIAL_H