#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	int score = 0, count = 0, index = 0;
	std::string name, sscore;
	std::vector<std::string> nameList;
	std::vector<int> scoreList, sortScoreList;
	std::vector<int>::iterator it;

	//open the file, and read the names and scores in
	std::ifstream file("scores.txt");
	while (file >> name >> score)
	{
		nameList.push_back(name);
		scoreList.push_back(score);
	}
	file.close();

	//sort the scores from the largest to the smallest in the copy vector
	sortScoreList = scoreList;
	std::sort(sortScoreList.begin(), sortScoreList.end());
	reverse(sortScoreList.begin(), sortScoreList.end());

	//compare the copy vector with the initial one to find the name of top 3
	for (count = 0; count < 3; count++)
	{
		it = std::find(scoreList.begin(), scoreList.end(), sortScoreList[count]);
		index = std::distance(scoreList.begin(), it);
		std::cout << nameList[index] << std::endl
			<< scoreList[index] << std::endl;
	}
}