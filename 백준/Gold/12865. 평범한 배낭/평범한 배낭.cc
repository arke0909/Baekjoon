#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int  arr[101][100001], dp[101][100001];
int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n, k;
	vector<pair<int, int>> vec;

	cin >> n >> k;

	for (int i = 0; i < n; ++i)
	{
		int weight, value;
		cin >> weight >> value;
		vec.push_back({ weight, value });
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			int currentWeight = vec[i - 1].first;
			int currentValue = vec[i - 1].second;

			if (currentWeight <= j)
			{
				arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - currentWeight] + currentValue);
			}
			else
			{
				arr[i][j] = arr[i - 1][j];
			}
		}
	}

	cout << arr[n][k];
}
