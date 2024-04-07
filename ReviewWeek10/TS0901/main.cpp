#include <iostream>
#include <string>
#include <map>

int main()
{
	int m, n;
	while (std::cin >> m >> n)
	{
		if (m == 0 && n == 0)break;
		std::map<char, std::map<char, bool>> dict;

		//one charcter can be translated to itself
		for (char c = 'a'; c <= 'z'; c++)
		{
			for (char d = 'a'; d <= 'z'; d++)
			{
				if (c == d)
				{
					dict[c][d] = true;
				}
				else
					dict[c][d] == false;
			}
		}

		//input translating rules
		for (int i = 0; i < m; i++)
		{
			char from, to;
			std::cin >> from >> to;
			dict[from][to] = true;
		}

		//extend the translating rules
		for (char c = 'a'; c <= 'z'; c++)
		{
			for (char d = 'a'; d <= 'z'; d++)
			{
				if (dict[d][c] && d != c)
				{
					for (char e = 'a'; e <= 'z'; e++)
					{
						dict[d][e] = dict[d][e] || dict[c][e];
					}
				}
			}
		}

		//input word pairs
		for (int i = 0; i < n; i++)
		{
			std::string w1, w2;
			std::cin >> w1 >> w2;

			if (w1.size() != w2.size())
				std::cout << "no" << std::endl;
			else
			{
				bool match = true;
				for (int j = 0; j < w1.size(); j++)
				{
					match = match && dict[w1[j]][w2[j]];
				}

				if (match)
					std::cout << "yes" << std::endl;
				else
					std::cout << "no" << std::endl;
			}
		}
	}
}