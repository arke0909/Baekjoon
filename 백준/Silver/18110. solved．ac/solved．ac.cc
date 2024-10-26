#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main()
{
	int n;
	float res = 0, total = 0, trimmedMean;

	cin >> n;
	trimmedMean = round(n * 0.15f);
	int* nums = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
		total += nums[i];
	}

	sort(nums, nums + n);

	for (int i = 0; i < trimmedMean; i++)
	{
		total -= nums[i];
		total -= nums[n - 1 - i];
	}

	res = n != 0 ? round(total / (n - (2 * trimmedMean))) : 0;

	cout << res;
	return 0;
}