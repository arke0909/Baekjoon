#include <iostream>
#include <vector>

using namespace std;

unsigned long long typedef ull;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;
		vector<ull> dp(101, 0);

		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 1;
		dp[4] = 2;
		dp[5] = 2;

		for (int j = 6, l = 1; j < 101; ++j, ++l)
		{
			dp[j] = dp[j - 1] + dp[l];
		}

		cout << dp[n] << '\n';
	}

	return 0;
}