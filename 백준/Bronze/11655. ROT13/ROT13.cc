#include <iostream>
#include <vector>
#include <string>
using namespace std;int main() {	string str;
	
	getline(cin, str);

	for (int i = 0; i < str.size(); i++)
	{
		if ((str[i] > 47 && str[i] < 58) || str[i] == ' ') continue;

		int asc = str[i];
		if (asc + 13 > 'z' || (asc + 13 > 'Z' && asc + 13 < 'h'))
			asc -= 13;
		else
			asc += 13;

		str[i] = asc;
	}

	cout << str;
	return 0;
}