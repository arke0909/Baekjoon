#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int cnt, total = 0;
vector<int> dp;

int DP(int n)
{
	if (n <= 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 1;
	if (dp[n] != -1) return dp[n];

	dp[n] = DP(n - 1) + DP(n - 2);
	return dp[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> cnt;

	dp.resize(cnt + 1, -1);

	cout << DP(cnt) << '\n';

	return 0;
}