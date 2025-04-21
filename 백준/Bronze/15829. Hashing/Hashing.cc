#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	long long multiply = 1, result = 0;
	cin >> n;

	for (int i = 0; i < n; ++i, multiply *= 31)
	{
		char c;
		cin >> c;

		result += (c - 'a' + 1)* multiply;
        multiply %= 1234567891;
	}

	cout << result  % 1234567891;

	return 0;
}