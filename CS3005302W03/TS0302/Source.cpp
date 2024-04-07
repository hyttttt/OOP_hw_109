#include <iostream>
#include <fstream>

int main()
{
	int num = 0, count[6] = { 0 };
	
	//open the file, and count the total number of each grade
	std::ifstream inputFile("grade.txt");
	while (inputFile >> num)
	{
		switch (num)
		{
		case 0:
			count[0]++;
			break;
		case 1:
			count[1]++;
			break;
		case 2:
			count[2]++;
			break;
		case 3:
			count[3]++;
			break;
		case 4:
			count[4]++;
			break;
		case 5:
			count[5]++;
			break;
		default:
			break;
		}
	}
	inputFile.close();

	//output the result
	std::ofstream outputFile("grades.Output");
	outputFile << count[0] << " grade(s) of 0" << std::endl
		<< count[1] << " grade(s) of 1" << std::endl
		<< count[2] << " grade(s) of 2" << std::endl
		<< count[3] << " grade(s) of 3" << std::endl
		<< count[4] << " grade(s) of 4" << std::endl
		<< count[5] << " grade(s) of 5" ;
	outputFile.close();
}