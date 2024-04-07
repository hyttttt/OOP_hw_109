#ifndef NUMBER_GAME_H
#define NUMBER_GAME_H
#include <string>
#include <vector>

class NumberGame
{
public:
	int a;
	std::string fileName;
	std::vector <long long int> s;
	std::vector<int> aDigits;
	std::vector<bool> check;
	std::vector<int> combination;
	std::vector<long long int> valid;

	void SetInput(int);
	void ProcessInput(void);
	void SetFileName(std::string);
	void LoadNumberList(void);
	void PrintAllValid(void);
	void Reset(void);
	void Combi(std::vector<int>, int, int, int, std::vector<bool>, unsigned int);
};

#endif // NUMBER_GAME_H