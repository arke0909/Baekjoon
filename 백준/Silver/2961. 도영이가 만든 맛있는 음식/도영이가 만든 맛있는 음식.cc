#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	long long result = 1e5;
	vector<pair<int, int>> ingre;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int s, b;
		cin >> s >> b;
		ingre.push_back({ s, b });
	}

	for (int i = 1; i < (1 << n); ++i)
	{
		long long total_S = 1;
		long long total_B = 0;

		for (int j = 0; j < ingre.size(); ++j)
		{
			if (i & (1 << j))
			{
				total_S *= ingre[j].first;
				total_B += ingre[j].second;
			}
		}

		result = min(result, abs(total_S - total_B));
	}

	cout << result;
}


