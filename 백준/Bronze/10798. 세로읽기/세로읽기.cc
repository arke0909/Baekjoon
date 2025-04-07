#include <iostream>
#include <string>
using namespace std;

int main()
{
	int size = 5, length = 0;

	string str[5];

	for (int i = 0; i < size; ++i)
	{
		cin >> str[i];

		if (length < str[i].size())
			length = str[i].size();
	}

	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if(str[j].length() > i)
			cout << str[j][i];
		}
	}


}
