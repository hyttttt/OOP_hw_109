// Name: ½²´ð¼ü
// Date:  April 20, 2021
// Last Update: April 20, 2021
// Problem statement: Find the Levenshtein distance between two words or two sentences

#include <iostream>
#include <string>
#include <math.h> 

// Intent: Calculate the Levenshtein distance between two words or two sentences
// Pre: Input two string to compare
// Post: Retrun the Levenshtein distance
int calculate(std::string w1, std::string w2)
{
	int row = (int)w1.size() + 1;
	int col = (int)w2.size() + 1;

	//create a 2d array to find similarity
	int** similarity;
	similarity = new int* [row];
	for (int i = 0; i < row; i++)
	{
		similarity[i] = new int[col];
	}

	//initialize the first row and column with ascending numbers from 0 (0, 1, 2, 3...)
	for (int i = 0; i < col; i++)
	{
		similarity[0][i] = i;
	}

	for (int i = 0; i < row; i++)
	{
		similarity[i][0] = i;
	}

	/*Levenshtein distance algorithm*/
	//When the alphabets at the same position of two words equal, temp = 1, otherwise temp = 0
	//Find the minimum among [i-1][j]+1, [i][j-1]+1, and [i-1][j-1]+temp
	//The minimum is value of [i][j], and so forth
	//Levenshtein distance is the value in the right bottom corner
	for (int i = 1; i < row; i++)
	{
		for (int j = 1; j < col; j++)
		{
			int temp = 1;
			if (w1[i - 1] == w2[j - 1])
			{
				temp = 0;
			}
			similarity[i][j] = std::min(std::min(similarity[i - 1][j] + 1, similarity[i][j - 1] + 1), similarity[i - 1][j - 1] + temp);
		}
	}

	int result = similarity[row - 1][col - 1];

	//delete dynamic array
	for (int i = 0; i < row; i++)
	{
		delete[] similarity[i];
	}
	delete[] similarity;

	return result;
}

int main()
{
	std::string input;
	std::string line1, line2;
	int count = 0;

	while (std::getline(std::cin, input))
	{
		count++;
		if (count == 1)
		{
			line1 = input;
			continue;
		}
		else if (count == 2)
		{
			line2 = input;

			if (line1 == line2)
			{
				std::cout << '0' << std::endl;
				continue;
			}

			if (line1.empty() || line2.empty())
			{
				std::cout << std::max(line1.size(), line2.size()) << std::endl;
				continue;
			}

			std::cout << calculate(line1, line2) << std::endl;

			count = 0;
		}
	}
}