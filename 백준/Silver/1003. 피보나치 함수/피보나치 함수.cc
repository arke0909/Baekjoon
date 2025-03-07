#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int cnt, zero, one = 0;
vector<int> dp;
vector<int> zeroCnt;
vector<int> oneCnt;


int DP(int n)
{
	if (n <= 0)
	{
		zero++;
		return 0;
	}
	if (n == 1)
	{
		one++;
		return 1;
	}


	if (dp[n] != -1)
	{
		zero += zeroCnt[n];
		one += oneCnt[n];
		return dp[n];
	}

	dp[n] = DP(n - 1) + DP(n - 2);
	
	zeroCnt[n] = zero;
	oneCnt[n] = one;

	return dp[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> cnt;

	for (int i = 0; i < cnt; i++)
	{
		int value;

		cin >> value;

		zero = one = 0;
		dp.resize(value + 1, -1);
		zeroCnt.resize(value + 1, -1);
		oneCnt.resize(value + 1, -1);

		DP(value);

		cout << zero << ' ' << one << '\n';
	}

	return 0;
}