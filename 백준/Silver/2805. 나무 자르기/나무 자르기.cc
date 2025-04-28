#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long m, result;

bool Check(int* arr, int len, long long target)
{
	long long cnt = 0;

	for (int i = 0; i < len; i++)
	{
		if (arr[i] <= target)
			continue;

		long long v = arr[i] - target;
		cnt += v;
	}

	if (cnt >= m)
		return true;
	else
		return false;
}

void BinarySearch(int* arr, int len)
{
	long long low = 0, high = arr[len - 1];

	while (low <= high)
	{
		long long  mid = (low + high) / 2;

		if (Check(arr, len, mid))
		{
			result = result > mid ? result : mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	int* arr = new int[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);
	BinarySearch(arr, n);

	cout << result;

	return 0;
}