#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

unsigned int k, n, length;

bool Check(int* arr, int len, int target)
{
	int cnt = 0;

	for (int i = 0; i < len; i++)
	{
		cnt += arr[i] / target;
	}

	if (cnt >= n)
		return true;
	else
		return false;
}

void BinarySearch(int* arr, int len)
{
	unsigned int low = 1, high = arr[len - 1];

	while (low <= high)
	{
		unsigned int  mid = (low + high) / 2;

		if (Check(arr, len, mid))
		{
			length = max(length, mid);
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


	cin >> k >> n;

	int* lan = new int[k];

	for (int i = 0; i < k; i++)
	{
		cin >> lan[i];
	}

	sort(lan, lan + k);

	BinarySearch(lan, k);

	cout << length;

	return 0;
}