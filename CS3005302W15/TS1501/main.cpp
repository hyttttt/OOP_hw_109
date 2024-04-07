// Name: ½²´ð¼ü
// Date:  June 8, 2021
// Last Update: June 4, 2021
// Problem statement: Use set to store data imported from the file
#include <iostream>
#include <fstream>
#include <set>
#include <string>

int main()
{
	std::ifstream openFile;
	std::string str;
	std::set<std::string> names;

	//open file and read all lines
	openFile.open("name.txt");
	while (std::getline(openFile, str))
	{
		names.insert(str);
	}
	openFile.close();

	//output
	std::set<std::string>::iterator iter = names.begin();
	for (; iter != names.end(); iter++)
	{
		std::cout << *iter << std::endl;
	}
}