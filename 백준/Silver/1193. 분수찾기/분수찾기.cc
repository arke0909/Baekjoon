#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n;
	cin >> n;
	int x, y , line = 1;

	while (true)
	{
		if (n - line <= 0)
			break;

		n -= line;
		line++;
	}

	if (line % 2 == 0)
	{
		x = 0;
		y = line + 1;

		for (int i = 0; i < n; ++i)
		{
			x++;
			y--;
		}
	}
	else
	{
		x = line + 1;
		y = 0;
		for (int i = 0; i < n; ++i)
		{
			x--;
			y++;
		}
	}

	cout << x << '/' << y;

	return 0;
}