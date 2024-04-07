#ifndef PRIME_NUMBER_H
#define PRIME_NUMBER_H

class PrimeNumber {
public:
	int value;

	int get();
	PrimeNumber();
	PrimeNumber(int _value);
	PrimeNumber & operator++();
	PrimeNumber operator++(int);
	PrimeNumber & operator--();
	PrimeNumber operator--(int);
};

#endif // PRIME_NUMBER_H