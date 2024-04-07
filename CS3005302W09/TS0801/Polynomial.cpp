#include "Polynomial.h"
#include <math.h>

Polynomial::Polynomial(double* param, int size)
{
	for (int i = 0; i < size; i++)
	{
		this->coe.push_back(*(param + i));
	}
}

Polynomial::Polynomial(Polynomial& poly)
{
	for (int i = 0; i < poly.coe.size(); i++)
	{
		this->coe.push_back(poly.coe[i]);
	}
}

int Polynomial::mySize()
{
	std::vector<double> copy;
	for (int i = 0; i < this->coe.size(); i++)
	{
		copy.push_back(this->coe[i]);
	}

	int index = copy.size() - 1;
	while (copy[index] == 0.0)
	{
		copy.pop_back();
		index = copy.size() - 1;
	}

	return copy.size();
}

Polynomial& Polynomial::operator=(const Polynomial& poly)
{
	this->coe.clear();

	for (int i = 0; i < poly.coe.size(); i++)
	{
		this->coe.push_back(poly.coe[i]);
	}

	return *this;
}

double& Polynomial::operator[](int index)
{
	if (index >= this->mySize())
	{
		int i = index - this->mySize() + 1;
		for (; i > 0; i--)
		{
			this->coe.push_back(0.0);
		}
	}
	return this->coe[index];
}

Polynomial Polynomial::operator+(Polynomial poly)
{
	Polynomial result;
	int min = std::min(this->coe.size(), poly.coe.size());
	int max = std::max(this->coe.size(), poly.coe.size());
	for (int i = 0; i < min; i++)
	{
		int sum = this->coe[i] + poly.coe[i];
		result.coe.push_back(sum);
	}

	if (this->coe.size() > poly.coe.size())
	{
		for (int i = min; i < max; i++)
		{
			result.coe.push_back(this->coe[i]);
		}
	}
	else if (this->coe.size() < poly.coe.size())
	{
		for (int i = min; i < max; i++)
		{
			result.coe.push_back(poly.coe[i]);
		}
	}

	return result;
}

Polynomial Polynomial::operator+(double num)
{
	Polynomial result;
	for (int i = 0; i < this->coe.size(); i++)
	{
		result.coe.push_back(this->coe[i]);
	}

	result.coe[0] += num;

	return result;
}

Polynomial Polynomial::operator-(Polynomial poly)
{
	Polynomial result;
	int min = std::min(this->coe.size(), poly.coe.size());
	int max = std::max(this->coe.size(), poly.coe.size());
	for (int i = 0; i < min; i++)
	{
		int sum = this->coe[i] - poly.coe[i];
		result.coe.push_back(sum);
	}

	if (this->coe.size() > poly.coe.size())
	{
		for (int i = min; i < max; i++)
		{
			result.coe.push_back(this->coe[i]);
		}
	}
	else if (this->coe.size() < poly.coe.size())
	{
		for (int i = min; i < max; i++)
		{
			result.coe.push_back(-poly.coe[i]);
		}
	}

	return result;
}

Polynomial Polynomial::operator-(double num)
{
	Polynomial result;
	for (int i = 0; i < this->coe.size(); i++)
	{
		result.coe.push_back(this->coe[i]);
	}

	result.coe[0] -= num;

	return result;
}

Polynomial Polynomial::operator*(Polynomial poly)
{
	Polynomial result;
	int n = this->coe.size() + poly.coe.size() - 1;
	for (int i = 0; i < n; i++)
	{
		result.coe.push_back(0);
	}

	for (int i = 0; i < this->coe.size(); i++)
	{
		for (int j = 0; j < poly.coe.size(); j++)
		{
			result.coe[i + j] += this->coe[i] * poly.coe[j];
		}
	}

	return result;
}

Polynomial Polynomial::operator*(double num)
{
	Polynomial result;
	for (int i = 0; i < this->coe.size(); i++)
	{
		result.coe.push_back(num * this->coe[i]);
	}

	return result;
}

Polynomial operator*(double num, Polynomial poly)
{
	Polynomial result;
	for (int i = 0; i < poly.coe.size(); i++)
	{
		result.coe.push_back(num * poly.coe[i]);
	}

	return result;
}

Polynomial operator+(double num, Polynomial poly)
{
	Polynomial result;
	for (int i = 0; i < poly.coe.size(); i++)
	{
		result.coe.push_back(poly.coe[i]);
	}

	result.coe[0] += num;

	return result;
}

Polynomial operator-(double num, Polynomial poly)
{
	Polynomial result;
	for (int i = 0; i < poly.coe.size(); i++)
	{
		result.coe.push_back(-poly.coe[i]);
	}

	result.coe[0] = num + result.coe[0];

	return result;
}

double evaluate(const Polynomial& poly, const double& var)
{
	double sum = 0;
	for (int i = 0; i < poly.coe.size(); i++)
	{
		sum += poly.coe[i] * pow(var, i);
	}

	return sum;
}