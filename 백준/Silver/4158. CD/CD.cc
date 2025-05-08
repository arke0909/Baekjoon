#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	while (true)
	{
		int n, m, cnt = 0;
		cin >> n >> m;

		if (n == 0 && m == 0)
			break;

		unordered_map<int, int> map;

		for (int i = 0; i < n; ++i)
		{
			int v;
			cin >> v;
			map[v]++;
		}

		for (int i = 0; i < m; ++i)
		{
			int v;
			cin >> v;
			map[v]++;
			if (map[v] > 1)
				cnt++;
		}

		cout << cnt << '\n';
	}


}