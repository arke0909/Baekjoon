#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	cin >> n;

	dp.resize(n + 1, 0);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i <= n; ++i)
	{
		int min = 4;
		int num = 1;

		while (true)
		{
			int sqrtValue = num * num;

			if (sqrtValue > i)
				break;

			int idx = i - sqrtValue;

			if (dp[idx] + 1 < min)
			{
				min = dp[idx] + 1;
			}

			num++;
		}

		dp[i] = min;
	}

	cout << dp[n];

	return 0;
}