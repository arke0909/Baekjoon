#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;

	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
		else
			str[i] += 32;
	}

	cout << str;

	return 0;
}