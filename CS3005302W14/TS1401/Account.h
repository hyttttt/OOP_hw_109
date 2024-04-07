#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

class InsufficientFunds
{
public:
	const int error_code = 1;
	InsufficientFunds() {};
};

class NegativeDeposit
{
public:
	const int error_code = 2;
	NegativeDeposit() {};
};

class Account
{
private:
	double balance;

public:
	Account() { balance = 0; }
	Account(double initialDeposit) { balance = initialDeposit; }

	// Intent: Access the value of balance
	// Pre: No input needed
	// Post: Return balance
	double getBalance() { return balance; }

	// Intent: Deposit money in the account
	// Pre: Input the amount of the money
	// Post: The balance increases. If the input is negative, throw an exception.
	double deposit(double amount)
	{
		if (amount > 0) balance += amount;
		else
		{
			NegativeDeposit error_negative;
			throw error_negative;
		}

		return balance;
	}

	// Intent: Withdraw money in the account
	// Pre: Input the value of money
	// Post: The balance decreases. If the input is negative or exceeds the balance, throw an exception.
	double withdraw(double amount)
	{
		if ((amount > balance) || (amount < 0)) 
		{
			InsufficientFunds error_insufficient;
			throw error_insufficient;
		}
		else balance -= amount;

		return balance;
	}
};

#endif // !ACCOUNT_H