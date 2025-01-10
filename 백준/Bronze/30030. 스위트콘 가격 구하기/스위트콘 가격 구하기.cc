#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, result, hundreds = 0;
	cin >> n;

	while (true)
	{
		result = hundreds + (hundreds * 0.1f);

		if (result == n)
		{
			cout << hundreds;
			break;
		}

		hundreds += 100;
	}

}