#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

	int n;
	int maxN = -1001;
	vector<int> arr(100001);
	vector<int> dp(100001);

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
	}

	maxN = dp[1] = arr[1];

	for (int i = 2; i <= n; ++i)
	{
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		maxN = max(maxN, dp[i]);
	}

	cout << maxN;

	return 0;
}