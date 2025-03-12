#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;

int** dp;
int** triangle;
int result = 0, idx = 0, maxNum, n;

void DP()
{
	maxNum = dp[0][0] = triangle[0][0];

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				dp[i][j] = triangle[i][j] + dp[i - 1][j];
			else if (j == i)
				dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
			else
				dp[i][j] = triangle[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);

			maxNum = max(maxNum, dp[i][j]);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	triangle = new int* [n];
	dp = new int* [n];

	for (int i = 0; i < n; i++)
	{
		triangle[i] = new int[i + 1];
		dp[i] = new int[i + 1] {0};

		for (int j = 0; j <= i; j++)
			cin >> triangle[i][j];
	}

	DP();

	cout << maxNum;

	return 0;
}