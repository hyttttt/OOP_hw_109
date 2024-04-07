#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int num;
	std::vector<int> numList;
	std::vector<int> countList;

	//input the first number
	std::cin >> num;
	numList.push_back(num);
	countList.push_back(1);

	//input the rest of the numbers
	while (std::cin >> num)
	{
		std::vector<int>::iterator it = std::find(numList.begin(), numList.end(), num);

		//find the input in the number list
		if (it != numList.end())
		{
			int index = std::distance(numList.begin(), it);
			countList[index]++;
		}
		//does not find the input in the number list
		else
		{
			numList.push_back(num);
			countList.push_back(1);
		}
	}

	//bubble sort the numbers
	int i, nTemp, cTemp, j;
	for (j = numList.size() - 1; j > 0; j--)
	{
		for (i = 0; i < j; i++)
		{
			if (numList[i] < numList[i + 1])
			{
				nTemp = numList[i];
				numList[i] = numList[i + 1];
				numList[i + 1] = nTemp;

				cTemp = countList[i];
				countList[i] = countList[i + 1];
				countList[i + 1] = cTemp;
			}
		}
	}

	//output
	std::cout << "N\tcount" << std::endl;
	for (i = 0; i < numList.size(); i++)
	{
		if (i != numList.size() - 1)
		{
			std::cout << numList[i] << "\t" << countList[i] << std::endl;
		}
		else
			std::cout << numList[i] << "\t" << countList[i];
	}
}