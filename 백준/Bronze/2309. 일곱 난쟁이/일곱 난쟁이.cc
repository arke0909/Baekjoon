#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n[9], a = 0,b,c, total = 0;

	while (a < 9)
	{
		cin >> n[a];
		total += n[a];
		a++;
	}

	sort(n, n + 9);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int tot = total;
			if (i == j) continue;
			tot = total - n[i] - n[j];
			if (tot == 100)
			{
				b = i;
				c = j;
				break;
			}
			else tot = total;
		}
	}
		


	for (int i = 0; i < 9; i++)
	{
		if (i == b || i == c) continue;

		cout << n[i] << '\n';
	}

	return 0;
}