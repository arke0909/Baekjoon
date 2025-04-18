#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int m, result = 1;
	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;

		if (x == result)
			result = y;
		else if (y == result)
			result = x;
	}

	cout << result;
}