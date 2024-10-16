#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int main()
{
	int a, b, n, res = 0;

	cin >> a >> b >> n;

	if (a % b == 0)
		cout << 0;
	else
	{
		for (int i = 0; i < n; i++)
		{
			a *= 10;
			res = (a / b) % 10;
			a %= b;
		}

		cout << res;

	}

	return 0;
}