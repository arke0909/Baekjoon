#include <iostream>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	string str1, str2, str3;
	long long result;
	cin >> str1 >> str2 >> str3;

	if (str1 == "black")
	{
		result = 0;
	}
	else if (str1 == "brown")
	{
		result = 1;
	}
	else if (str1 == "red")
	{
		result = 2;
	}
	else if (str1 == "orange")
	{
		result = 3;
	}
	else if (str1 == "yellow")
	{
		result = 4;
	}
	else if (str1 == "green")
	{
		result = 5;
	}
	else if (str1 == "blue")
	{
		result = 6;
	}
	else if (str1 == "violet")
	{
		result = 7;
	}
	else if (str1 == "grey")
	{
		result = 8;
	}
	else if (str1 == "white")
	{
		result = 9;
	}

	result *= 10;

	if (str2 == "black")
	{
		result += 0;
	}
	else if (str2 == "brown")
	{
		result += 1;
	}
	else if (str2 == "red")
	{
		result += 2;

	}
	else if (str2 == "orange")
	{
		result += 3;

	}
	else if (str2 == "yellow")
	{
		result += 4;

	}
	else if (str2 == "green")
	{
		result += 5;
	}
	else if (str2 == "blue")
	{
		result += 6;
	}
	else if (str2 == "violet")
	{
		result += 7;
	}
	else if (str2 == "grey")
	{
		result += 8;
	}
	else if (str2 == "white")
	{
		result += 9;
	}

	if (str3 == "black")
	{
		result *= 1;
	}
	else if (str3 == "brown")
	{
		result *= 10;

	}
	else if (str3 == "red")
	{
		result *= 100;

	}
	else if (str3 == "orange")
	{
		result *= 1000;

	}
	else if (str3 == "yellow")
	{
		result *= 10000;

	}
	else if (str3 == "green")
	{
		result *= 100000;

	}
	else if (str3 == "blue")
	{
		result *= 1000000;

	}
	else if (str3 == "violet")
	{
		result *= 10000000;

	}
	else if (str3 == "grey")
	{
		result *= 100000000;

	}
	else if (str3 == "white")
	{
		result *= 1000000000;
	}

	cout << result;
}