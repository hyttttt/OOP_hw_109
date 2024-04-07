#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	unsigned int m, n;
	while (cin >> m >> n)
	{
		vector<unsigned char> memory(m, 0);

		for (int i = 0; i < n; i++)
		{
			string cmd, type;
			unsigned int pos;
			cin >> cmd >> pos >> type;

			//violation access
			if (pos >= m //char and string
				|| (type == "short" && m - pos < 2)
				|| (type == "int" && m - pos < 4))
			{
				cout << "Violation Access.\n";
				if (cmd == "Get") continue;
			}

			//read command
			if (cmd == "Get")
			{
				if (type == "char")
				{
					unsigned char* cPtr = &memory[pos];
					cout << char(*cPtr) << endl;
				}
				else if (type == "short")
				{
					unsigned short* sPtr = (unsigned short*)&memory[pos];
					cout << unsigned short(*sPtr) << endl;
				}
				else if (type == "int")
				{
					unsigned int* iPtr = (unsigned int*)&memory[pos];
					cout << unsigned int(*iPtr) << endl;
				}
				else if (type == "String")
				{
					while (pos < m && memory[pos] != '\0')
					{
						cout << memory[pos];
						pos++;
					}
					cout << endl;
				}
			}
			else if (cmd == "Set")
			{
				if (type == "String")
				{
					string str;
					getline(cin, str);

					//if there are blanks in the front of string, clear them
					while (str[0] == ' ')
						str = str.substr(1, str.size() - 1);

					//append the end of string
					str += '\0';

					for (unsigned int j = 0; j < str.size() && pos < m; j++, pos++)
					{
						memory[pos] = str[j];
					}

					if (pos == m)
						cout << "Violation Access.\n";
				}
				else
				{
					unsigned int val;
					cin >> val;

					if (type == "char")
					{
						memory[pos] = val & 0xff;
					}
					else if (type == "short")
					{
						if (m - pos < 2)
						{
							memory[pos] = val & 0xff;
						}
						else
						{
							unsigned short* sPtr = (unsigned short*)&memory[pos];
							*sPtr = val;
						}
					}
					else if (type == "int")
					{
						if (m - pos < 4)
						{
							while (pos < m)
							{
								memory[pos] = val & 0xff;
								val >>= 8;
								pos++;
							}
						}
						else
						{
							unsigned int* iPtr = (unsigned int*)&memory[pos];
							*iPtr = val;
						}
					}
				}
			}
		}
	}
}