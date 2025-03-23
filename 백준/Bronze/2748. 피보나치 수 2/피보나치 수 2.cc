#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
vector<long long> dp;

long long DP(long long n)
{
	if (n <= 0) return 0;
	if (n == 1) return 1;
	if (dp[n] != -1) return dp[n];

	dp[n] = DP(n - 1) + DP(n - 2);
	return dp[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	dp.resize(n + 1, -1);

	cout << DP(n) << '\n';

	return 0;
}