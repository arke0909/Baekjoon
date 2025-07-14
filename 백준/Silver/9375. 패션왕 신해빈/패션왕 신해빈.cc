#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	unordered_map<string, int> wardrobe;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int m;
		long long cnt = 1;
		cin >> m;
		for (int j = 0; j < m; ++j)
		{
			string  costume, part;
			cin >> costume >> part;

			wardrobe[part]++;
		}

		for (auto item : wardrobe)
		{
			cnt *= item.second + 1;
		}

		cout << cnt - 1 << '\n';
		wardrobe.clear();
	}
}
