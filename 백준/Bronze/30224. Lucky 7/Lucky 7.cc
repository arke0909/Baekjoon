#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	string str;
	cin >> str;

	n = stoi(str);

	bool isDivisiable = n % 7 == 0, isContainsSeven = str.find('7') != string::npos;

	if (isContainsSeven && isDivisiable)
	{
		cout << 3;
	}
	else if (isContainsSeven && !isDivisiable)
	{
		cout << 2;
	}
	else if (!isContainsSeven && isDivisiable)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
}