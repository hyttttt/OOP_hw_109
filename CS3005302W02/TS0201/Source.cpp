#include <iostream>
#include <vector>
#include <cmath>

int main()
{
	long long int amount, count;
	long double sum, average, sumOfSquaredDeviation, standardDeviation, number;

	while (std::cin >> amount)
	{
		std::vector<double> num;
		sum = 0.0;
		sumOfSquaredDeviation = 0.0;

		//get all the numbers and compute the sum
		for (count = 0; count < amount; count++)
		{
			std::cin >> number;

			num.push_back(number);
			sum += num[count];
		}

		//compute the average
		average = sum / amount;

		//compute the sum of squared deviation from mean
		for (count = 0; count < amount; count++)
		{
			sumOfSquaredDeviation += pow((num[count] - average), 2.0);
		}

		//compute the standard deviation
		standardDeviation = sqrt(sumOfSquaredDeviation / amount);

		//print out the result
		std::cout << "Average:" << average << "\tStandard deviation:" << standardDeviation << std::endl;
	}
}