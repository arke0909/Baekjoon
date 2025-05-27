#include <iostream>
using namespace std;

int main()
{
	int n, m, cnt = 0;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		int yes = 0, no = 0;
		for (int j = 0; j < m; ++j)
		{
			char c;
			cin >> c;
			if (c == 'O')
				yes++;
			else
				no++;
		}

		if (yes > no)
			cnt++;
	}

	cout << cnt;
}


