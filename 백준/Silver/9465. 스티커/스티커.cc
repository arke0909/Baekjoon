#include <iostream>
#include <algorithm>
using namespace std;
int  arr[2][100001], dp[2][100001];
int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int t, n;

	cin >> t;

	while (t--)
	{
		cin >> n;
		fill(arr[0], arr[0] + 100001, 0);
		fill(arr[1], arr[1] + 100001, 0);
		fill(dp[0], dp[0] + 100001, 0);
		fill(dp[1], dp[1] + 100001, 0);

		for (int j = 0; j < 2; ++j)
		{
			for (int i = 1; i <= n; ++i)
			{
				cin >> arr[j][i];
			}
		}

		dp[0][0] = dp[1][0] = 0;
		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];

		for (int i = 2; i <= n; ++i)
		{
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
		}

		cout << max(dp[0][n], dp[1][n]) << '\n';
	}
}