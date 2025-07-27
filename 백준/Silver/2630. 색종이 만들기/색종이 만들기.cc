#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, w = 0, b = 0;
int paper[128][128];

void DC(int x, int y, int size)
{
	if (size == 0) return;
	
	bool flag = true;

	int std = paper[y][x];

	for (int i = y; i < y + size; ++i)
	{
		for (int j = x; j < x + size; ++j)
		{
			if (std != paper[i][j])
				flag = false;
		}
	}

	if (!flag)
	{
		DC(x, y, size / 2);
		DC(x + size / 2, y, size / 2);
		DC(x, y + size / 2, size / 2);
		DC(x + size / 2, y + size / 2, size / 2);
	}
	else
	{
		if (std == 1)
			b++;
		else
			w++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> paper[i][j];
		}
	}

	DC(0, 0, n);

	cout << w << '\n' << b;
}