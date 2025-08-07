
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, q;
	cin >> m;

	vector<int> func(m + 1);
	vector<vector<int>> sparseTable(20, vector<int>(m + 1));

	for (int i = 1; i <= m; ++i)
	{
		cin >> func[i];
	}

	for (int i = 1; i <= m; ++i)
	{
		sparseTable[0][i] = func[i];
	}

	for (int i = 1; i < 20; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			int next = sparseTable[i - 1][j];
			sparseTable[i][j] = sparseTable[i - 1][next];
		}
	}

	cin >> q;

	for (int i = 0; i < q; ++i)
	{
		int n, x;
		cin >> n >> x;

		for (int bit = 19; bit >= 0; --bit)
		{
			if ((n & (1 << bit)) != 0)
				x = sparseTable[bit][x];
		}

		cout << x << '\n';
	}
}