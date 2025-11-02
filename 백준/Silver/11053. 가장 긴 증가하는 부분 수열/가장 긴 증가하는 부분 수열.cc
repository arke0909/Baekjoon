#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, arr[1000], lis[1000], answer = 0;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; ++i)
	{
		int temp = 0;

		for (int j = 0; j < i; ++j)
		{
			if (arr[i] > arr[j] && temp < lis[j])
			{
				temp = lis[j];
			}
		}

		lis[i] = temp + 1;
		answer = max(lis[i], answer);
	}

	cout << answer;
}
