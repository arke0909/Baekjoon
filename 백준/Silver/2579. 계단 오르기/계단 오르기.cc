#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int dp[301]{ -1 };
int score[301];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	fill_n(dp, 301, -1);
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> score[i];
	}

	dp[0] = 0;
	dp[1] = score[1];
	dp[2] = max(score[2], score[2] + dp[1]);

	for (int i = 3; i <= n; ++i)
	{
		dp[i] = max(dp[i - 2] + score[i], score[i - 1] + score[i] + dp[i - 3]);
	}

	cout << dp[n];

	return 0;
}