#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, originInven, target = 0, top = 0, minN = 2147483647;
	cin >> n >> m >> originInven;

	int** map = new int* [n];

	for (int i = 0; i < n; ++i)
	{
		map[i] = new int[m];
		for (int j = 0; j < m; ++j)
		{
			cin >> map[i][j];
			target = max(target, map[i][j]);
		}
	}

	for (int i = 0; i <= target; ++i)
	{
		int getBlock = 0, useBlock = 0, t = 0, inventory = originInven;

		for (int j = 0; j < n; ++j)
		{
			for (int l = 0; l < m; ++l)
			{
				if (i < map[j][l])
				{
					getBlock += (map[j][l] - i);
				}
				else
				{
					useBlock += (i - map[j][l]);
				}
			}
		}

		t += getBlock * 2;
		inventory += getBlock;

		if (inventory >= useBlock)
		{
			t += useBlock;
			inventory -= useBlock;
		}
		else
			continue;

		if (minN == t)
		{
			top = max(top, i);
		}
		else if(minN > t)
		{
			minN = t;
			top = i;
		}
	}


	cout << minN << ' ' << top;
}